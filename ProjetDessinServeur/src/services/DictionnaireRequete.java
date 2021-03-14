package services;

public class DictionnaireRequete { // Class de façade permettant de parcourir la chaîne de responsabilité

	Requete requeteDebut;

	public DictionnaireRequete() {
		super();

		// Création des requêtes de la COR
		RequeteCOR effacerDessins = new EffacerDessins(null);
		RequeteCOR fermerFenetre = new FermerFenetre(effacerDessins);
		RequeteCOR dessinSegment = new DessinSegment(fermerFenetre);
		RequeteCOR dessinTriangle = new DessinTriangle(dessinSegment);
		RequeteCOR dessinRond = new DessinRond(dessinTriangle);
		RequeteCOR dessinCroix = new DessinCroix(dessinRond);
		RequeteCOR ouvrirFenetre = new OuvrirFenetre(dessinCroix);

		this.requeteDebut = ouvrirFenetre; // Affectation de la première requête de la COR
	}

	public Requete getRequeteDebut() { // Fonction de récupération de la première requête
		return requeteDebut;
	}

}