#include "Croix.h"
#include "VisitorDessin.h"


int Croix::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Croix::Traslation()
{
	return 0;
}
int Croix::Homothetie()
{
	return 0;
}
int Croix::Rotation()
{
	return 0;
}

const Croix & Croix::operator=(const Croix & c)
{
	if (this != &c) {
		this->setColor(c.getColor());
		this->_vecteurOrigine = c._vecteurOrigine;
		this->_diagonale = this->_diagonale;
	}
	return *this;
}