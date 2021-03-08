#include "Client.h"

Client * Client::_instance = nullptr;

Client::Client() {
	try {
		if (WSAStartup(MAKEWORD(2, 0), &this->WSAData))
			throw Erreur("L'initialisation a échoué");

		this->sock = socket(this->familleAdresses, this->typeSocket, this->protocole);

		if (this->sock == INVALID_SOCKET)
			throw Erreur("Erreur initialisation socket");

		cout << "tapez l'adresse IP du serveur de dessin : " << endl;
		cin >> adresseServeur;
		cout << "tapez le port du serveur du serveur de dessin : " << endl;
		cin >> portServeur;

		this->sockaddr.sin_family = AF_INET;
		this->sockaddr.sin_addr.s_addr = inet_addr(this->adresseServeur);
		this->sockaddr.sin_port = htons(this->portServeur);

		if (connect(this->sock, (SOCKADDR *)&this->sockaddr, sizeof(this->sockaddr)) == SOCKET_ERROR)
			throw Erreur("Erreur connection socket");
		else
			cout << "creeation socket reussite" << endl;

	}catch (Erreur erreur) {
		cerr << erreur << endl;
	}

}

Client::~Client()
{
	if (this->_instance) {
		try {
			if (shutdown(this->sock, SD_BOTH) == SOCKET_ERROR)
				throw Erreur("Erreur shutdown socket");

			if (closesocket(this->sock))
				throw Erreur("Erreur close socket");

			WSACleanup();
			cout << "Fermeture de la connection serveur" << endl;

		}catch (Erreur erreur) {
			cerr << erreur << endl;
		}
	}
}

void Client::rqtServ(string rqt)
{
	try {
		if (send(this->sock, rqt.c_str(), rqt.size(), 0) == SOCKET_ERROR)
			throw Erreur("Erreur d'envoi");
		else
			cout << "Envoi reussi" << endl;
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}
