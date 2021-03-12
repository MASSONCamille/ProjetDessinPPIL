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
