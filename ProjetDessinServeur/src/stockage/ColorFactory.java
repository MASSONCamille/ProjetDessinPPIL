package stockage;

import java.awt.Color;
import java.util.HashMap;

public final class ColorFactory { // Color factory (singleton) permettant de récupérer les couleurs et de les
									// utiliser

	private static ColorFactory instance = null;

	public HashMap<String, Color> listColor; // Liste des couleurs

	private ColorFactory() {
		this.listColor = new HashMap<String, Color>();
		listColor.put("0", Color.BLACK);
		listColor.put("1", Color.BLUE);
		listColor.put("2", Color.RED);
		listColor.put("3", Color.GREEN);
		listColor.put("4", Color.YELLOW);
		listColor.put("5", Color.CYAN);
	}

	public static ColorFactory getInstance() {
		if (instance == null) {
			instance = new ColorFactory();
		}
		return instance;
	}

	public HashMap<String, Color> getListColor() {
		return listColor;
	}

	public void setListColor(HashMap<String, Color> listColor) {
		this.listColor = listColor;
	}

	public Color getColor(String key) { // Fonction de récupération d'une couleur
		return this.listColor.get(key);
	}

}