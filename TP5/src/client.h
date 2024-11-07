/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

/*
 * port d'ordinateur pour envoyer et recevoir des messages
 */
#define PORT 8089

/** fonction pour envoyer une operation de calcul formatée au serveur 
 * @param socketfd Le descripteur de la socket.
 * @param operateur opérateur +, -, *, /
 * @param num1 Le premier nombre.
 * @param num2 Le deuxième nombre
 * @return 0 en cas de succes, -1 en cas d'erreur
 */
int envoie_operateur_numeros(int socketfd, char *data, char *operateur, int num1, int num2);

/**
 * Fonction pour lire les notes de chaque étudiant dans un tableau 2D.
 * @param notes Tableau 2D pour stocker les notes de chaque étudiant.
 * @return Le nombre total d'étudiants pour lesquels les notes ont été lues.
 */
int lire_notes(int notes[NB_ETUDIANTS][NB_NOTES]);

/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd);


#endif
