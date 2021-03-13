package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.ColorFactory;
import stockage.FrameFactory;

public class DessinRond extends RequeteCOR {

	public DessinRond(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) {
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("rond") && donnees.length == 6) {

			Frame fen = FrameFactory.getInstance().getFrame(noConnexion, donnees[1]);

			int numBuffers = 2;
			fen.createBufferStrategy(numBuffers);

			try {
				Thread.sleep(150);
			} catch (InterruptedException e) {
				System.err.println("Erreur dans la mise en pause du thread");
			}

			BufferStrategy strategie = fen.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();

			graphics.setColor(ColorFactory.getInstance().getColor(donnees[2]));

			int x = Integer.parseInt(donnees[3]);
			int y = Integer.parseInt(donnees[4]);
			int r = Integer.parseInt(donnees[5]);

			graphics.drawOval(x, y, r, r);

			strategie.show();

			graphics.dispose();

			return true;
		} else
			return false;
	}

}
