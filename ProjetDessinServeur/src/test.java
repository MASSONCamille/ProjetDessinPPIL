import java.awt.Frame;
import java.util.ArrayList;

import stockage.InfoFrame;

public class test {

	public static ArrayList<InfoFrame> listFrame = new ArrayList<InfoFrame>();

	public static InfoFrame getInfoFrame(int noConnexion, String noFrame) {
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
			return infoFrameVerif;
		else
			return new InfoFrame();
	}

	public static void main(String[] args) {
		listFrame.add(new InfoFrame(1, "1", new Frame()));
		listFrame.add(new InfoFrame(1, "2", new Frame()));
		listFrame.add(new InfoFrame(1, "3", new Frame()));
		listFrame.add(new InfoFrame(2, "1", new Frame()));
		listFrame.add(new InfoFrame(2, "2", new Frame()));
		listFrame.add(new InfoFrame(3, "1", new Frame()));

		System.out.println(listFrame.get(0).toString());
		System.out.println(listFrame.get(1).toString());
		System.out.println(listFrame.get(5).toString());

		System.out.println("\n\n");

		System.out.println(getInfoFrame(1, "1").toString());
		System.out.println(getInfoFrame(1, "2").toString());
		System.out.println(getInfoFrame(3, "1").toString());
		System.out.println(getInfoFrame(4, "1").toString());
		System.out.println(getInfoFrame(3, "2").toString());
	}

}
