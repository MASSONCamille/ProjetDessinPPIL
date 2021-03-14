package stockage;

import java.awt.Frame;
import java.util.ArrayList;

public final class FrameFactory { // Frame factory (singleton) permettant de récupérer les frames et de les
	// utiliser en fonction du client

	private static FrameFactory instance = null;

	public ArrayList<InfoFrame> listFrame = new ArrayList<InfoFrame>(); // Liste des frames

	private FrameFactory() {
	}

	public static FrameFactory getInstance() {
		if (instance == null) {
			instance = new FrameFactory();
		}
		return instance;
	}

	public ArrayList<InfoFrame> getListFrame() {
		return listFrame;
	}

	public Frame getFrame(int noConnexion, String noFrame) { // Permets de récupérer directement une frame en fonction
																// du
																// client et du numéro de celle-ci
		boolean trouve = false;
		int i = 0;
		int taille = listFrame.size();
		InfoFrame infoFrameVerif = new InfoFrame(); // InfoFrame de comparaison

		while (!trouve && i < taille) {
			infoFrameVerif = listFrame.get(i);
			if (infoFrameVerif.getNoConnexion() == noConnexion && infoFrameVerif.getNoFrame().equals(noFrame)) {
				trouve = true;
			}
			i++;
		}

		if (trouve)
			return infoFrameVerif.getFen();
		else
			return new InfoFrame().getFen();
	}

	public void fermerFrame(int noConnexion, String noFrame) { // Permets de fermer et d'enlever la frame de la liste
		int i = 0;
		boolean trouve = false;
		InfoFrame temp = null;

		while (i < listFrame.size() && trouve == false) {
			if (listFrame.get(i) != null) {
				temp = listFrame.get(i);
				if (temp.getNoConnexion() == noConnexion && temp.getNoFrame().equals(noFrame)) {
					temp.getFen().dispose();
					listFrame.remove(i);
					trouve = true;
				}
			}
			i++;
		}
	}

	public void emptyAllFramesClient(int noConnexion) { // Permets de fermer et de retirer toutes les frames d'un client
		ArrayList<InfoFrame> collecSuppr = new ArrayList<InfoFrame>();

		listFrame.forEach((n) -> {
			if (n.getNoConnexion() == noConnexion) {
				n.getFen().dispose();
				collecSuppr.add(n);
			}
		});
		if (!collecSuppr.isEmpty())
			listFrame.removeAll(collecSuppr);
	}

}