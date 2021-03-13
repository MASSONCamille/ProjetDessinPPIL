package services;

import java.awt.Frame;

import stockage.FrameFactory;

public class EffacerDessins extends RequeteCOR {

	public EffacerDessins(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) {
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("effacer") && donnees.length == 2) {
			Frame fen = FrameFactory.getInstance().getFrame(noConnexion, donnees[1]);

			fen.removeAll();

			return true;
		} else
			return false;
	}

}
