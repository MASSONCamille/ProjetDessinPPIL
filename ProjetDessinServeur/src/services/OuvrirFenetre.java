package services;

import java.awt.Frame;

import stockage.FrameFactory;
import stockage.InfoFrame;

public class OuvrirFenetre extends RequeteCOR {

	public OuvrirFenetre(RequeteCOR requeteCORsuivant) {
		super(requeteCORsuivant);
	}

	@Override
	protected boolean actionHandlerBis(String instruction, int noConnexion) {
		String[] donnees = instruction.split("/");
		if (donnees[0].equals("ouvrirfenetre") && donnees.length == 7) {

			Frame fen = new Frame(donnees[2]);

			int x = Integer.parseInt(donnees[3]);
			int y = Integer.parseInt(donnees[4]);
			int width = Integer.parseInt(donnees[5]);
			int high = Integer.parseInt(donnees[6]);
			int numBuffers = 2;

			fen.setBounds(x, y, width, high);
			fen.setVisible(true);
			fen.setIgnoreRepaint(true);
			fen.setResizable(false);
			fen.createBufferStrategy(numBuffers);
			try {
				Thread.sleep(150);
			} catch (InterruptedException e) {
				System.err.println("Erreur dans la mise en pause du thread");
			}

			FrameFactory.getInstance().getListFrame().add(new InfoFrame(noConnexion, donnees[1], fen));

			return true;
		} else
			return false;
	}

}