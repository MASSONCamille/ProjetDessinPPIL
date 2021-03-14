package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.FrameFactory;

public class EffacerDessins extends RequeteCOR { // Class de requ�te permettant d'effacer les dessins d'une fen�tre si
													// l'instruction correspond

	public EffacerDessins(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) { // V�rifie l'instruction et le nombre de
																				// param�tres
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("effacer") && donnees.length == 2) {
			Frame fen = FrameFactory.getInstance().getFrame(noConnexion, donnees[1]); // R�cup�ration de la frame
			fen.removeAll(); // Retire les components

			// R�cup�ration du buffer strategy et d'un graphics pour effacer les dessins
			BufferStrategy strategie = fen.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();
			graphics.clearRect(fen.getX(), fen.getY(), fen.getWidth(), fen.getHeight()); // Efface les dessins

			strategie.show();
			graphics.dispose();

			return true;
		} else
			return false;
	}

}
