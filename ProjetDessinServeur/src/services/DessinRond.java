package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.SingletonListFrame;

public class DessinRond extends RequeteCOR {

	public DessinRond(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) {
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("rond") && donnees.length == 5) {
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

			int x = Integer.parseInt(donnees[2]);
			int y = Integer.parseInt(donnees[3]);
			int r = Integer.parseInt(donnees[4]);

			graphics.drawOval(x, y, r, r);

			strategie.show();

			graphics.dispose();

			return true;
		} else
			return false;
	}

}
