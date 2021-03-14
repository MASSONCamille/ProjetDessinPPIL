package serveur;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

import services.DictionnaireRequete;
import stockage.FrameFactory;

public class TheadClientHandler extends Thread { // Class dédié au client qui reçoit ses instructions
	Socket socket;
	int noConnexion;

	BufferedReader fluxEntrant;
	PrintStream fluxSortant;

	public TheadClientHandler(Socket socket, ThreadGroup groupe, int noConnexion) throws IOException {
		super(groupe, "TheadClientHandler");
		this.socket = socket;
		this.noConnexion = noConnexion;

		fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
		fluxSortant = new PrintStream(this.socket.getOutputStream());
	}

	public void run() {
		String instruction;
		DictionnaireRequete dicoRequete = new DictionnaireRequete(); // Création du dictionnaire des requêtes pour ce
																		// thread

		try {
			while (!isInterrupted()) { // Boucle qui attend les instructions du client tant que la connexion n'est pas
										// interrompue
				instruction = fluxEntrant.readLine();
				if (instruction != null) {
					instruction = instruction.toLowerCase().trim();
					System.out.println("Le client n° " + this.noConnexion + " a envoyé : ");
					System.out.println(instruction);
					boolean resRequete = dicoRequete.getRequeteDebut().actionHandler(instruction, noConnexion);
					// Utilisation du dictionnaire des requêtes
					if (resRequete)
						System.out.println("Instruction terminé");
					else
						System.out.println("Instruction introuvable");
				}
				sleep(5);
			}
		} catch (InterruptedException erreur) {
		} catch (IOException erreur) {
			System.err.println("Impossible de lire le Socket");
		}

		FrameFactory.getInstance().emptyAllFramesClient(noConnexion); // Ferme les fenêtres du client si ce n'est pas
																		// fait
		System.out.println("Le client n° " + this.noConnexion + " a terminé sa session.");

	}
}
