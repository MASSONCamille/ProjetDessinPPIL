package services;

import stockage.FrameFactory;

public class FermerFenetre extends RequeteCOR { // Class de requête permettant de fermer une fenêtre si l'instruction
												// correspond

	public FermerFenetre(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) { // Vérifie l'instruction et le nombre de
																				// paramètres
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("fermer") && donnees.length == 2) {
			FrameFactory.getInstance().fermerFrame(noConnexion, donnees[1]); // Fermeture de la fenêtre via la frame
																				// factory

			return true;
		} else
			return false;
	}

}
