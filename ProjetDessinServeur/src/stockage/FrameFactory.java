package stockage;

import java.awt.Frame;
import java.util.ArrayList;

public final class SingletonListFrame {

	private static SingletonListFrame instance;

	public ArrayList<InfoFrame> listFrame = new ArrayList<InfoFrame>();

	private SingletonListFrame() {
	}

	public static SingletonListFrame getInstance() {
		if (instance == null) {
			instance = new SingletonListFrame();
		}
		return instance;
	}

	public ArrayList<InfoFrame> getListFrame() {
		return listFrame;
	}

	public Frame getFrame(int noConnexion, String noFrame) {
		boolean trouve = false;
		int i = 0;
		int taille = listFrame.size();
		InfoFrame infoFrameVerif = new InfoFrame();

		while (!trouve && i < taille) {
			infoFrameVerif = listFrame.get(i);
			if (infoFrameVerif.getNoConnexion() == noConnexion && infoFrameVerif.getNoFrame() == noFrame) {
				trouve = true;
			}
			i++;
		}

		if (trouve)
			return infoFrameVerif.getFen();
		else
			return new InfoFrame().getFen();
	}

	public void emptyAllFramesClient(int noConnexion) {
		ArrayList<InfoFrame> collecSuppr = new ArrayList<InfoFrame>();

		listFrame.forEach((n) -> {
			if (n.getNoConnexion() == noConnexion)
				collecSuppr.add(n);
		});
		if (!collecSuppr.isEmpty())
			listFrame.removeAll(collecSuppr);
	}

}