#include "SauvgTxt.h"

int SauvgTxt::Sauvgarde(const Cercle *c) const
{
	cout << "Nom du ficher de sauvgarde, si le fichier existe deja il sera efface !!!" << endl;
	string nom;
	cin >> nom;	// recuperation du nom
	while (cin.get() != '\n') {} // vidage du buffer

	ofstream fichier(("../Sauvegardes/" + nom + ".txt").c_str());
	if (fichier) {

		fichier << c->getColor() << "/"
			<< c->getVec().getX() << "/"
			<< c->getVec().getY() << "/"
			<< c->getRayon();

		return 0;
	}
	else {
		cout << "impossible d'ouvrir: " << nom << endl;

		return 1;
	}
}

int SauvgTxt::Sauvgarde(const Croix *c) const
{
	cout << "Nom du ficher de sauvgarde, si le fichier existe deja il sera efface !!!" << endl;
	string nom;
	cin >> nom;	// recuperation du nom
	while (cin.get() != '\n') {} // vidage du buffer

	ofstream fichier(("../Sauvegardes/" + nom + ".txt").c_str());
	if (fichier) {

		fichier << c->getColor() << "/"
				<< c->getVec().getX() << "/"
				<< c->getVec().getY() << "/"
				<< c->getDiagonale().getX() << "/"
				<< c->getDiagonale().getY();

		return 0;
	}
	else return 1;
}

int SauvgTxt::Sauvgarde(const Segment *s) const
{
	cout << "Nom du ficher de sauvgarde, si le fichier existe deja il sera efface !!!" << endl;
	string nom;
	cin >> nom;	// recuperation du nom
	while (cin.get() != '\n') {} // vidage du buffer

	ofstream fichier(("../Sauvegardes/" + nom + ".txt").c_str());
	if (fichier) {

		fichier << s->getColor() << "/"
				<< s->getVec().getX() << "/"
				<< s->getVec().getY() << "/"
				<< s->getPoint().getX() << "/"
				<< s->getPoint().getY();

		return 0;
	}
	else return 1;
}

int SauvgTxt::Sauvgarde(const Polygone *p) const
{
	cout << "Nom du ficher de sauvgarde, si le fichier existe deja il sera efface !!!" << endl;
	string nom;
	cin >> nom;	// recuperation du nom
	while (cin.get() != '\n') {} // vidage du buffer

	ofstream fichier(("../Sauvegardes/" + nom + ".txt").c_str());
	if (fichier) {

		fichier << p->getColor() << "/"
				<< p->getVec().getX() << "/"
				<< p->getVec().getY() << "/"
				<< (p->getNbPoint()-1);

		for (Vecteur2D v : p->getListPoint()) {
			fichier << "/" << v.getX()
					<< "/" << v.getY();
		}

		return 0;
	}
	else return 1;
}

int SauvgTxt::Sauvgarde(const Triangle *t) const
{
	cout << "Nom du ficher de sauvgarde, si le fichier existe deja il sera efface !!!" << endl;
	string nom;
	cin >> nom;	// recuperation du nom
	while (cin.get() != '\n') {} // vidage du buffer

	ofstream fichier(("../Sauvegardes/" + nom + ".txt").c_str());
	if (fichier) {

		fichier << t->getColor() << "/"
				<< t->getVec().getX() << "/"
				<< t->getVec().getY() << "/"
				<< t->getP2().getX() << "/"
				<< t->getP2().getY() << "/"
				<< t->getP3().getX() << "/"
				<< t->getP3().getY();

		return 0;
	}
	else return 1;
}
