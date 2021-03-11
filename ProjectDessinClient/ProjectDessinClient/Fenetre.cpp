#include "Fenetre.h"
#include "VisitorDessin.h"

int Fenetre::nbFen = 0;


int Fenetre::Dessiner(VisitorDessin * v)
{
	int res = v->Dessiner(this);
	if (!res) {
		this->_dessiner = true;
		return res;
	}
}

int Fenetre::Effacer(VisitorDessin * v)
{
	return v->Effacer(this);
}
