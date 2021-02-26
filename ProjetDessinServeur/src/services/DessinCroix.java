package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.SingletonListFrame;

public class DessinCroix extends RequeteCOR {

	public DessinCroix(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) {
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("croix") && donnees.length == 6) {
			Frame fen = SingletonListFrame.getInstance().getFrame(noConnexion, donnees[1]);

			int numBuffers = 2;
			fen.createBufferStrategy(numBuffers);
			try {
				Thread.sleep(150);
			} catch (InterruptedException e) {
				System.err.println("Erreur dans la mise en pause du thread");
			}

			BufferStrategy strategie = fen.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();

			int x1 = Integer.parseInt(donnees[2]);
			int y1 = Integer.parseInt(donnees[3]);
			int x2 = Integer.parseInt(donnees[4]);
			int y2 = Integer.parseInt(donnees[5]);

			graphics.drawLine(x1, y1, x2, y2);

			graphics.drawLine(x1, x2, y2, y1);

			strategie.show();

			graphics.dispose();

			return true;
		} else
			return false;
	}

}
