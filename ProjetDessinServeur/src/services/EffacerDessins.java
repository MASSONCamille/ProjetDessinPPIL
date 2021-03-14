package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.FrameFactory;

public class EffacerDessins extends RequeteCOR { // Class de requête permettant d'effacer les dessins d'une fenêtre si
													// l'instruction correspond

	public EffacerDessins(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) { // Vérifie l'instruction et le nombre de
																				// paramètres
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("effacer") && donnees.length == 2) {
			Frame fen = FrameFactory.getInstance().getFrame(noConnexion, donnees[1]); // Récupération de la frame
			fen.removeAll(); // Retire les components

			// Récupération du buffer strategy et d'un graphics pour effacer les dessins
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
