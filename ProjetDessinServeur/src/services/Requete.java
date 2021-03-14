package services;

public abstract class Requete { // Class abstraite d'une requête

	public abstract boolean actionHandler(String instruction, int noConnexion); // Fonction d'action qui récupère
																				// l'instruction du client et son numéro
																				// de connexion

}
