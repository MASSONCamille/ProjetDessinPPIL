#include "Fenetre.h"
#include "VisitorDessin.h"

int Fenetre::nbFen = 0;


int Fenetre::Afficher(VisitorDessin * v)
{
	int res = v->Afficher(this);
	if (!res) {
		this->_afficher = true;
		return res;
	}
	else return 1;
}

int Fenetre::Effacer(VisitorDessin * v)
{
	return v->Effacer(this);
}

int Fenetre::Detruire(VisitorDessin * v)
{
	int res = v->Detruire(this);
	if (!res) {
		delete this;
		return res;
	}
	else return 1;
}

ostream & operator<<(ostream & os, const Fenetre &f)
{
	return os << f.getNomFen() << " [num: " << f.getNumFen()
		<< ", " << f.getHeight() << "/" << f.getHeight() << "]";
}
