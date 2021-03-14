package services;

import stockage.FrameFactory;

public class FermerFenetre extends RequeteCOR { // Class de requ�te permettant de fermer une fen�tre si l'instruction
												// correspond

	public FermerFenetre(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) { // V�rifie l'instruction et le nombre de
																				// param�tres
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("fermer") && donnees.length == 2) {
			FrameFactory.getInstance().fermerFrame(noConnexion, donnees[1]); // Fermeture de la fen�tre via la frame
																				// factory

			return true;
		} else
			return false;
	}

}
