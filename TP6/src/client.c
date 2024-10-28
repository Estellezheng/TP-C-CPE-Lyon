/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"
#include "bmp.h"
#include "cJSON.h"
#include "cJSON_Utils.h"

/*
 * Fonction concertit l'objet JSON en une chaine de caractères
 * Il faut un argument : l'objet JSON
 */
char* from_root_to_json_string(cJSON *root) {
  // Convertit l'objet JSON en une chaîne de caractères
  char *json_string = cJSON_Print(root);
  return json_string;
}

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd, cJSON *root){
  char data[1024];
  memset(data, 0, sizeof(data));  // reintialise

  // Demandez à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, sizeof(message), stdin);

  // creation de l'objet JSON
  // Ajoute la valeur à la clé "code" dans le JSON
  cJSON_AddStringToObject(root, "code", "message");
  // Crée un tableau pour la clé "valeurs" et l'ajoute au JSON
  cJSON *valeurs = cJSON_CreateArray();
  cJSON_AddItemToObject(root, "valeurs", valeurs);
  cJSON_AddItemToArray(valeurs, cJSON_CreateString(message)); // ajoute dans le tableau "valeurs" la chaine de caractères message

  // conversion en JSON 
  char *json_string = from_root_to_json_string(root);
  strcpy(data, json_string);

  // envoi des donnees
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0){
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0){
    perror("erreur lecture");
    return -1;
  }

  // Analyse json_string pour recréer un objet JSON
  cJSON *root_copy = cJSON_Parse(data);

  // Récupère la valeur à la clé "code"
  cJSON *code_copy = cJSON_GetObjectItem(root_copy, "code");

  // Vérifie que code_copy est bien une chaine de caractères et que sa valeur n'est pas une chaine vide
  if (cJSON_IsString(code_copy) && (code_copy->valuestring != NULL)) {
    if (strcmp(code_copy->valuestring, "message") == 0) {
      // Récupère le tableau "valeurs" et parcourt ses éléments
      cJSON *valeurs_copy = cJSON_GetObjectItem(root_copy, "valeurs");
      if (cJSON_IsArray(valeurs_copy)) {
          cJSON *item = NULL;
          cJSON_ArrayForEach(item, valeurs_copy) {
              if (cJSON_IsString(item)) {
                  printf("Message recu: %s\n", item->valuestring);
              }
          }
      } 
      else {
          printf("L'élément 'valeurs' n'est pas un tableau valide.\n");
      }
    }
  } 
  else {
      printf("L'élément 'code' n'est pas une chaîne de caractères valide.\n");
  }

  // Libère la mémoire
  cJSON_Delete(root);
  cJSON_Delete(root_copy);
  free(json_string);

  return 0;
}

void analyse(char *pathname, cJSON *root, int nmb_couleurs){
  // compte de couleurs
  couleur_compteur *cc = analyse_bmp_image(pathname);
  int count;
  cJSON_AddStringToObject(root, "code", "couleurs"); // ajoute la valeur à la clé "code" dans le JSON

  // Crée un tableau pour la clé "valeurs" et l'ajoute au JSON
  cJSON *valeurs = cJSON_CreateArray();
  cJSON_AddItemToObject(root, "valeurs", valeurs);

  char temp_string[nmb_couleurs];
  sprintf(temp_string, "%d,", nmb_couleurs);

  if (cc->size < nmb_couleurs){
    sprintf(temp_string, "%d,", cc->size);
  }
  cJSON_AddItemToArray(valeurs, cJSON_CreateString(temp_string)); // ajoute dans le tableau "valeurs" la chaine de caractères temp_string
  
  // ajout des couleurs au tableau
  for (count = 1; count < (nmb_couleurs+1) && cc->size - count > 0; count++){ 
    // Ajoute dans le tableau "valeurs" toutes les chaines de caractères temp_string (à chaque itération), sauf la dernière
    if (count > 1) {
      cJSON_AddItemToArray(valeurs, cJSON_CreateString(temp_string));
    }
    if (cc->compte_bit == BITS32){
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc24[cc->size - count].c.rouge, cc->cc.cc32[cc->size - count].c.vert, cc->cc.cc32[cc->size - count].c.bleu);
    }
    if (cc->compte_bit == BITS24){
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc32[cc->size - count].c.rouge, cc->cc.cc32[cc->size - count].c.vert, cc->cc.cc32[cc->size - count].c.bleu);
    }
  }

  // Ajoute la dernière chaine temp_string en enlevant la dernière virgule
  temp_string[strlen(temp_string) - 1] = '\0';
  cJSON_AddItemToArray(valeurs, cJSON_CreateString(temp_string));
}

int envoie_couleurs(int socketfd, char *pathname, int nmb_couleurs, cJSON *root){ 
  char data[1024];
  memset(data, 0, sizeof(data));
  analyse(pathname, root, nmb_couleurs);

  char *json_string = from_root_to_json_string(root);
  strcpy(data, json_string);

  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0){
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // Libère la mémoire
  cJSON_Delete(root);
  free(json_string);

  return 0;
}

int main(int argc, char **argv){
  int socketfd;

  struct sockaddr_in server_addr;

  if ((argc != 3) && (argc != 1)){
    printf("usage couleurs: ./client chemin_bmp_image nombre_de_couleurs\n");
    //return (EXIT_FAILURE);
  }

  if ((argc != 3) && (argc != 1)){
    printf("usage messages: ./client\n");
    //return (EXIT_FAILURE);
  }

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0){
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0){
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  // Création de l'objet JSON principal
  cJSON *root = cJSON_CreateObject();

  if (argc == 1){
    // envoyer et recevoir un message
    envoie_recois_message(socketfd, root);
  }
  else if (argc == 3){
    int nmb_couleurs = atoi(argv[2]); // transforme la chaine de caractères en un entier

    if ((nmb_couleurs > 30) || (nmb_couleurs < 10)) {
      printf("Le nombre_de_couleurs doit être entre 10 et 30\n");
      exit(EXIT_FAILURE);
    }

    else {
      // Envoyer et recevoir les couleurs prédominantes
      // d'une image au format BMP (argv[1])
      envoie_couleurs(socketfd, argv[1], nmb_couleurs, root);
    }
  }

  close(socketfd);
}
