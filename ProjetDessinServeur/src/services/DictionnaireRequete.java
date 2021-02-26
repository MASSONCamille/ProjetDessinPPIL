package services;

public class DictionnaireRequete {

	Requete requeteDebut;

	public DictionnaireRequete() {
		super();

		RequeteCOR effacerDessins = new EffacerDessins(null);
		RequeteCOR dessinRond = new DessinRond(effacerDessins);
		RequeteCOR dessinCroix = new DessinCroix(dessinRond);
		RequeteCOR ouvrirFenetre = new OuvrirFenetre(dessinCroix);

		this.requeteDebut = ouvrirFenetre;
	}

	public Requete getRequeteDebut() {
		return requeteDebut;
	}

}