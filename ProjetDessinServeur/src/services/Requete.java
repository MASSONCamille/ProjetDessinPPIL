package services;

public abstract class Requete { // Class abstraite d'une requ�te

	public abstract boolean actionHandler(String instruction, int noConnexion); // Fonction d'action qui r�cup�re
																				// l'instruction du client et son num�ro
																				// de connexion

}
