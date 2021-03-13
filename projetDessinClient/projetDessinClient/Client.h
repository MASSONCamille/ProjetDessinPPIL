#pragma once

#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"

#pragma comment(lib, "ws2_32.lib")

#define L 200 // longueur adresse serveur

class Client
{
private:
	static Client *_instance;						// instance de singleton
	
	WSADATA WSAData;
	SOCKET sock;
	int familleAdresses = AF_INET;					// IPv4
	int typeSocket = SOCK_STREAM;					// mode connecté TCP
	int protocole = IPPROTO_TCP;
	char adresseServeur[L];
	short portServeur;
	SOCKADDR_IN sockaddr;

	Client();										// constructeur prive
	virtual ~Client();										// destructeur prive


public:

	Client(const Client *) = delete;				// constructeur par recopie interdit
	Client & operator=(const Client &) = delete;	// copie via opérateur = interdit

	static Client * getInstance() {					// recuperation/creation de l'instance
		if (!_instance)
			_instance = new Client;
		return _instance;
	}

	void rqtServ(string);


	void fermerClient();
};

