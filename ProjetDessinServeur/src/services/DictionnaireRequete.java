package services;

public class DictionnaireRequete { // Class de fa�ade permettant de parcourir la cha�ne de responsabilit�

	Requete requeteDebut;

	public DictionnaireRequete() {
		super();

		// Cr�ation des requ�tes de la COR
		RequeteCOR effacerDessins = new EffacerDessins(null);
		RequeteCOR fermerFenetre = new FermerFenetre(effacerDessins);
		RequeteCOR dessinSegment = new DessinSegment(fermerFenetre);
		RequeteCOR dessinTriangle = new DessinTriangle(dessinSegment);
		RequeteCOR dessinRond = new DessinRond(dessinTriangle);
		RequeteCOR dessinCroix = new DessinCroix(dessinRond);
		RequeteCOR ouvrirFenetre = new OuvrirFenetre(dessinCroix);

		this.requeteDebut = ouvrirFenetre; // Affectation de la premi�re requ�te de la COR
	}

	public Requete getRequeteDebut() { // Fonction de r�cup�ration de la premi�re requ�te
		return requeteDebut;
	}

}