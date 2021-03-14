package services;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import stockage.ColorFactory;
import stockage.FrameFactory;

public class DessinTriangle extends RequeteCOR { // Class de requête permettant de dessiner un triangle si l'instruction
													// correspond

	public DessinTriangle(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) { // Vérifie l'instruction et le nombre de
																				// paramètres
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("triangle") && donnees.length == 9) {
			Frame fen = FrameFactory.getInstance().getFrame(noConnexion, donnees[1]); // Récupération de la frame

			// Récupération du buffer strategy et d'un graphics pour dessiner sur la frame
			BufferStrategy strategie = fen.getBufferStrategy();
			Graphics graphics = strategie.getDrawGraphics();

			graphics.setColor(ColorFactory.getInstance().getColor(donnees[2]));

			int x1 = Integer.parseInt(donnees[3]);
			int y1 = Integer.parseInt(donnees[4]);
			int x2 = Integer.parseInt(donnees[5]);
			int y2 = Integer.parseInt(donnees[6]);
			int x3 = Integer.parseInt(donnees[7]);
			int y3 = Integer.parseInt(donnees[8]);

			// Création des trois lignes du triangle
			graphics.drawLine(x1, y1, x2, y2);
			graphics.drawLine(x2, y2, x3, y3);
			graphics.drawLine(x3, y3, x1, y1);

			strategie.show();
			graphics.dispose();

			return true;
		} else
			return false;
	}

}
