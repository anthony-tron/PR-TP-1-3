/*
 * Client HTTP 0.9
 * */
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "socketUtils.h"

#define ADRESSE_SERVEUR "139.124.187.23"
#define PORT_SERVEUR 80
#define TAILLE_MAX_REPONSE 128

void exitErreur(const char * msg)
{
    perror(msg);
    exit( EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " /chemin/du/fichier" << std::endl;
        return EXIT_FAILURE;
    }

    std::string chemin_fichier(argv[1]);

    int socket_client = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_client == -1)
        exitErreur("socket");

    struct sockaddr_in socket_serveur;
        socket_serveur.sin_family = AF_INET;
        socket_serveur.sin_port = htons(PORT_SERVEUR);
        inet_aton(ADRESSE_SERVEUR, &socket_serveur.sin_addr);

    if (connect(socket_client, (sockaddr*)&socket_serveur, sizeof(sockaddr_in)) == -1)
        exitErreur("connect");

    std::string requete = "GET " + chemin_fichier + "\n";
    write(socket_client, requete.c_str(), requete.length());

    try {
        std::cout << su::readEntirelyFrom(socket_client) << std::endl;
    } catch (...) {
        std::cout << "Erreur" << std::endl;
    }

    return 0;
}

