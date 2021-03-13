package services;

import stockage.FrameFactory;

public class FermerFenetre extends RequeteCOR {

	public FermerFenetre(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) {
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("fermer") && donnees.length == 2) {
			FrameFactory.getInstance().fermerFrame(noConnexion, donnees[1]);

			return true;
		} else
			return false;
	}

}
