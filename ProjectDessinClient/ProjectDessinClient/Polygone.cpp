#include "Polygone.h"
#include "VisitorDessin.h"


int Polygone::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Polygone::Traslation()
{
	return 0;
}
int Polygone::Homothetie()
{
	return 0;
}
int Polygone::Rotation()
{
	return 0;
}

const Polygone & Polygone::operator=(const Polygone & p)
{
	if (this != &p) {
		this->setColor(p.getColor());
		this->_vecteurOrigine = p._vecteurOrigine;
		this->_nbPoint = p._nbPoint;
		this->_listPoint = p._listPoint;
	}
	return *this;
}