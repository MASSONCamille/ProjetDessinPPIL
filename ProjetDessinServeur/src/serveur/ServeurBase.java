package serveur;

import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class ServeurBase { // Class du serveur de base. Permets de lancer le serveur et de recevoir des
							// clients en les redirigeant vers des threads d�di�s
	public static void main(String[] args) throws Exception { // Bas� sur le prototype vu en cours
		ServerSocket serveur;
		serveur = new ServerSocket(9111);

		System.out.println("Serveur d�marr� : " + serveur);

		InetAddress cetteMachine;
		int portLocal;
		ThreadGroup groupe;

		portLocal = serveur.getLocalPort();

		cetteMachine = InetAddress.getLocalHost();

		System.out.println("Adresse IP du serveur : " + cetteMachine.getHostAddress());
		System.out.println("Port du serveur : " + portLocal);

		groupe = new ThreadGroup("socketsClients");
		int noConnexion = 0;
		while (true) { // Boucle infinie en attente de clients
			Socket nouveauClientSocket;
			TheadClientHandler nouveauClientThread;

			nouveauClientSocket = serveur.accept();
			++noConnexion;
			System.out.println("Connexion r�ussie n� " + noConnexion);

			nouveauClientThread = new TheadClientHandler(nouveauClientSocket, groupe, noConnexion);
			nouveauClientThread.start(); // Lance un thread d�di� au client
		}
	}

}
