#include "Cercle.h"
#include "VisitorDessin.h"


int Cercle::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Cercle::Traslation()
{
	return 0;
}
int Cercle::Homothetie()
{
	return 0;
}
int Cercle::Rotation()
{
	return 0;
}

const Cercle & Cercle::operator=(const Cercle & c)
{
	if (this != &c) {
		this->setColor(c.getColor());
		this->_vecteurOrigine = c._vecteurOrigine;
		this->_rayon = this->_rayon;
	}
	return *this;
}