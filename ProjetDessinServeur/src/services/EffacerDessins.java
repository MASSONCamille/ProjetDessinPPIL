package services;

import java.awt.Frame;

import stockage.SingletonListFrame;

public class EffacerDessins extends RequeteCOR {

	public EffacerDessins(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) {
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("effacer") && donnees.length == 2) {
			Frame fen = SingletonListFrame.getInstance().getFrame(noConnexion, donnees[1]);

			fen.removeAll(); // A voir

			return true;
		} else
			return false;
	}

}
