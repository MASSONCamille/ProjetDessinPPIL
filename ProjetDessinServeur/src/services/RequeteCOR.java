package services;

public abstract class RequeteCOR extends Requete { // Class requ�te de la cha�ne de responsabilit� qui impl�mente la
													// class Requ�te
	RequeteCOR requeteCORsuivant;

	protected RequeteCOR(RequeteCOR requeteCORsuivant) { // Constructeur basique d'une COR
		this.requeteCORsuivant = requeteCORsuivant;
	}

	public boolean actionHandler(String instruction, int noConnexion) { // Permets de passer � la requ�te en cas d'�chec
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
																						// requ�tes

}
