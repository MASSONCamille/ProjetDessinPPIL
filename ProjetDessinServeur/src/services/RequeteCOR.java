package services;

public abstract class RequeteCOR extends Requete {
	RequeteCOR requeteCORsuivant;

	protected RequeteCOR(RequeteCOR requeteCORsuivant) {
		this.requeteCORsuivant = requeteCORsuivant;
	}

	public boolean actionHandler(String instruction, int noConnexion) {
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

	protected abstract boolean actionHandlerBis(String instruction, int noConnexion);

}
