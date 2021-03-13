package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

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
			BufferStrategy strategie = fen.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();
			graphics.clearRect(fen.getX(), fen.getY(), fen.getWidth(), fen.getHeight());

			strategie.show();

			graphics.dispose();

			return true;
		} else
			return false;
	}

}
