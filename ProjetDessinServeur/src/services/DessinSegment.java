package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.ColorFactory;
import stockage.FrameFactory;

public class DessinSegment extends RequeteCOR { // Class de requ�te permettant de dessiner un segment si l'instruction
												// correspond

	public DessinSegment(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) { // V�rifie l'instruction et le nombre de
																				// param�tres
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("segment") && donnees.length == 7) {
			Frame fen = FrameFactory.getInstance().getFrame(noConnexion, donnees[1]); // R�cup�ration de la frame

			// R�cup�ration du buffer strategy et d'un graphics pour dessiner sur la frame
			BufferStrategy strategie = fen.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();

			graphics.setColor(ColorFactory.getInstance().getColor(donnees[2]));

			int x1 = Integer.parseInt(donnees[3]);
			int y1 = Integer.parseInt(donnees[4]);
			int x2 = Integer.parseInt(donnees[5]);
			int y2 = Integer.parseInt(donnees[6]);

			// Cr�ation de la ligne du segment
			graphics.drawLine(x1, y1, x2, y2);

			strategie.show();
			graphics.dispose();

			return true;
		} else
			return false;
	}

}
