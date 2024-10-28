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

/** fonction pour envoyer une operation de calcul au serveur
* @param socketfd Le descripteur de la socket.
 * @param operateur opérateur +, -, *, /
 * @param num1 Le premier nombre.
 * @param num2 Le deuxième nombre 
 * @return 0 en cas de succes, -1 en cas d'erreur
 */
int envoie_operateur_numeros(int socketfd, char *data, char *operateur, int num1, int num2) {
  // Format du message avec l'opération et les nombres
  snprintf(data, 1024, "calcule : %s %d %d", operateur, num1, num2);
  return 0;
}


/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message et recuperation dans la var message
  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);

  // 2 cas message ou calcul
  // verification format calcul
  char operateur[2];
  int num1, num2;
  if (sscanf(message, "%1s %d %d", operateur, &num1, &num2) == 3 && 
      (strcmp(operateur, "+") == 0 || strcmp(operateur, "/") == 0)) {   // seulement les cas addition et division sont traités dans le contexte de l'exo
    envoie_operateur_numeros(socketfd, data, operateur, num1, num2);
  }
  else{
    // Construit le message avec une étiquette "message: "
    strcpy(data, "message: ");
    strcat(data, message);
  }

  // Envoie le message (var data) au client
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Lit les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  // Affiche le message reçu du serveur
  printf("Message reçu: %s\n", data);

  return 0; // Succès
}



int main()
{
  int socketfd;

  struct sockaddr_in server_addr;

  //Creation d'une socket
   
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
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
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    // appeler la fonction pour envoyer un message au serveur
    envoie_recois_message(socketfd);
  }

  close(socketfd);
}