/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>

#include "serveur.h"

int socketfd; // Déclaration globale de socketfd

/**
 * Cette fonction envoie un message (*data) au client (client_socket_fd)
 * @param client_socket_fd : Le descripteur de socket du client.
 * @param sdata : Le message à envoyer.
 * @return EXIT_SUCCESS en cas de succès, EXIT_FAILURE en cas d'erreur.
 */
int renvoie_message(int client_socket_fd, char *data)
{
   // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);
  strncpy(data, message, sizeof(message));
  int data_size = write(client_socket_fd, (void *)data, strlen(data));

  if (data_size < 0)
  {
    perror("Erreur d'écriture");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

// cette fonction renvoie le résultat d'une opération après la demande calcle d'un client
int recois_numeros_calcule (int client_socket_fd, char *data){
  char operateur[2];
  int num1, num2;
  int resultat;

  // Extraction de l'opérateur et des nombres et calcul
    if (sscanf(data, "calcule : %s %d %d", operateur, &num1, &num2) == 3) {
        if (strcmp(operateur, "+") == 0) {
            resultat = num1 + num2;
        } else if (strcmp(operateur, "/") == 0) {
            if (num2 != 0) {
                resultat = num1 / num2;
            } else {
                write(client_socket_fd, "Erreur: division par zéro", 25);
                return -1;
            }
        } else {
            write(client_socket_fd, "Erreur: opérateur inconnu", 26);
            return -1;
        }
    } 
    else {    // format incorect pour le traitement de l'operation
        write(client_socket_fd, "Erreur: format incorrect", 23);
        return -1;
    }

    // Envoie le résultat au client
    char resultat_message[50];
    sprintf(resultat_message, "%d", resultat);
    snprintf(resultat_message, sizeof(resultat_message), "calcule : %d", resultat);
    write(client_socket_fd, resultat_message, strlen(resultat_message));

    return 0;
}


/**
 * Cette fonction lit les données envoyées par le client,
 * et renvoie un message en réponse.
 * @param socketfd : Le descripteur de socket du serveur.
 * @param data : Le message.
 * @return EXIT_SUCCESS en cas de succès, EXIT_FAILURE en cas d'erreur.
 */
int recois_envoie_message(int client_socket_fd, char *data)
{
  printf("Message reçu: %s\n", data);
  char code[10];

  // 2 cas 
  if (sscanf(data, "%9s:", code) == 1){ //  chaîne de 9 caractères stockée dans code à partir de data 
    if (strcmp(code, "calcule") == 0){  // si le message commence par calcule => il effectue et renvoie l'operation
      recois_numeros_calcule(client_socket_fd, data);
    }
    else{             // sinon renvoie le message par défaut
      renvoie_message(client_socket_fd, data);
    }
  }
  else {
      // Si le format n'est pas reconnu, renvoie un message d'erreur        
      write(client_socket_fd, "Erreur: format du message non reconnu", 36);
  }

  return (EXIT_SUCCESS);
}

/**
 * Gestionnaire de signal pour Ctrl+C (SIGINT).
 * @param signal : Le signal capturé (doit être SIGINT pour Ctrl+C).
 */
void gestionnaire_ctrl_c(int signal)
{
  printf("\nSignal Ctrl+C capturé. Sortie du programme.\n");

  // Fermer le socket si ouvert
  if (socketfd != -1)
  {
    close(socketfd);
  }

  exit(0); // Quitter proprement le programme.
}


/**
 * Gère la communication avec un client spécifique.
 *
 * @param client_socket_fd Le descripteur de socket du client à gérer.
 */
void gerer_client(int client_socket_fd)
{
  char data[1024];

  while (1)
  {
    // Réinitialisation des données
    memset(data, 0, sizeof(data));

    // Lecture des données envoyées par le client
    int data_size = read(client_socket_fd, data, sizeof(data));

    if (data_size <= 0)
    {
      // Erreur de réception ou déconnexion du client
      if (data_size == 0)
      {
        // Le client a fermé la connexion proprement
        printf("Client déconnecté.\n");
      }
      else
      {
        perror("Erreur de réception");
      }

      // Fermer le socket du client et sortir de la boucle de communication
      close(client_socket_fd);
      break; // Sortir de la boucle de communication avec ce client
    }

    recois_envoie_message(client_socket_fd, data);
  }
}

/**
 * Configuration du serveur socket et attente de connexions.
 */
// gerer_client > recois_envoie_message > renvoie_message ou recois_numeros_calcule

int main()
{
  int bind_status;                // Statut de la liaison
  struct sockaddr_in server_addr; // Structure pour l'adresse du serveur
  int option = 1;                 // Option pour setsockopt

  // Création d'une socket
  socketfd = socket(AF_INET, SOCK_STREAM, 0);


  // Vérification si la création de la socket a réussi
  if (socketfd < 0)
  {
    perror("Impossible d'ouvrir une socket");
    return -1;
  }

  // Configuration de l'option SO_REUSEADDR pour permettre la réutilisation de l'adresse du serveur
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  // Initialisation de la structure server_addr
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);       // Port d'écoute du serveur
  server_addr.sin_addr.s_addr = INADDR_ANY; // Accepter les connexions de n'importe quelle adresse

  // Liaison de l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Vérification si la liaison a réussi
  if (bind_status < 0)
  {
    perror("bind");
    return (EXIT_FAILURE);
  }

  // Enregistrement de la fonction de gestion du signal Ctrl+C
  signal(SIGINT, gestionnaire_ctrl_c);

  // Mise en attente de la socket pour accepter les connexions entrantes jusqu'à une limite de 10 connexions en attente
  listen(socketfd, 10);

  printf("Serveur en attente de connexions...\n");

  struct sockaddr_in client_addr;                     // Structure pour l'adresse du client
  unsigned int client_addr_len = sizeof(client_addr); // Longueur de la structure client_addr
  int client_socket_fd;                               // Descripteur de socket du client

  // Boucle infinie
  while (1)
  {
    // Nouvelle connexion cliente
    client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);

    if (client_socket_fd < 0)
    {
      perror("accept");
      continue; // Continuer à attendre d'autres connexions en cas d'erreur
    }

    // Créer un processus enfant pour gérer la communication avec le client
    pid_t child_pid = fork();

    if (child_pid == 0)
    {
      // Code du processus enfant
      close(socketfd); // Fermer la socket du serveur dans le processus enfant
      gerer_client(client_socket_fd);
      exit(0); // Quitter le processus enfant
    }
    else if (child_pid < 0)
    {
      perror("fork");
      close(client_socket_fd); // Fermer le socket du client en cas d'erreur
    }
    else
    {
      // Code du processus parent
      close(client_socket_fd); // Fermer le socket du client dans le processus parent
    }
  }

  // Le programme ne devrait jamais atteindre cette ligne dans la boucle infinie
  return 0;
}