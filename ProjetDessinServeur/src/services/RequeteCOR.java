package services;

public abstract class RequeteCOR extends Requete { // Class requête de la chaîne de responsabilité qui implémente la
													// class Requête
	RequeteCOR requeteCORsuivant;

	protected RequeteCOR(RequeteCOR requeteCORsuivant) { // Constructeur basique d'une COR
		this.requeteCORsuivant = requeteCORsuivant;
	}

	public boolean actionHandler(String instruction, int noConnexion) { // Permets de passer à la requête en cas d'échec
		boolean resultat = actionHandlerBis(instruction, noConnexion);

		if (resultat != false)
			return resultat;
		else {
			if (requeteCORsuivant != null)
				return requeteCORsuivant.actionHandler(instruction, noConnexion);
			else
				return false;
		}

	}

	protected abstract boolean actionHandlerBis(String instruction, int noConnexion); // Fonction abstraite d'action des
																						// requêtes

}
