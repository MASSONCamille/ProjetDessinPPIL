package services;

public class DictionnaireRequete {

	Requete requeteDebut;

	public DictionnaireRequete() {
		super();

		RequeteCOR effacerDessins = new EffacerDessins(null);
		RequeteCOR dessinSegment = new DessinSegment(effacerDessins);
		RequeteCOR dessinTriangle = new DessinTriangle(dessinSegment);
		RequeteCOR dessinRond = new DessinRond(dessinTriangle);
		RequeteCOR dessinCroix = new DessinCroix(dessinRond);
		RequeteCOR ouvrirFenetre = new OuvrirFenetre(dessinCroix);

		this.requeteDebut = ouvrirFenetre;
	}

	public Requete getRequeteDebut() {
		return requeteDebut;
	}

}