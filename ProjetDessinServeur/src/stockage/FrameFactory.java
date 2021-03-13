package stockage;

import java.awt.Frame;
import java.util.ArrayList;

public final class FrameFactory {

	private static FrameFactory instance = null;

	public ArrayList<InfoFrame> listFrame = new ArrayList<InfoFrame>();

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

	public Frame getFrame(int noConnexion, String noFrame) {
		boolean trouve = false;
		int i = 0;
		int taille = listFrame.size();
		InfoFrame infoFrameVerif = new InfoFrame();

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