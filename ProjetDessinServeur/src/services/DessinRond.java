package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.ColorFactory;
import stockage.FrameFactory;

public class DessinRond extends RequeteCOR { // Class de requ�te permettant de dessiner un rond (cercle) si
												// l'instruction correspond

	public DessinRond(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) { // V�rifie l'instruction et le nombre de
																				// param�tres
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("rond") && donnees.length == 6) {
			Frame fen = FrameFactory.getInstance().getFrame(noConnexion, donnees[1]); // R�cup�ration de la frame

			// R�cup�ration du buffer strategy et d'un graphics pour dessiner sur la frame
			BufferStrategy strategie = fen.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();

			graphics.setColor(ColorFactory.getInstance().getColor(donnees[2]));

			int x = Integer.parseInt(donnees[3]);
			int y = Integer.parseInt(donnees[4]);
			int r = Integer.parseInt(donnees[5]);

			// Cr�ation du cercle
			graphics.drawOval(x, y, r, r);

			strategie.show();
			graphics.dispose();

			return true;
		} else
			return false;
	}

}
