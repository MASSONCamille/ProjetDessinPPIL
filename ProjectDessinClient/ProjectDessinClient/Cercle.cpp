#include "Cercle.h"


Cercle::~Cercle()
{
}

int Cercle::Dessiner() const
{
	return 0;
}
int Cercle::Traslation() const
{
	return 0;
}
int Cercle::Homothetie() const
{
	return 0;
}
int Cercle::Rotation() const
{
	return 0;
}

const Cercle & Cercle::operator=(const Cercle & c)
{
	if (this != &c) {
		this->_color = c._color;
		this->_vecteurOrigine = c._vecteurOrigine;
		this->_rayon = this->_rayon;
	}
	return *this;
}