#include "Cercle.h"
#include "VisitorDessin.h"


int Cercle::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Cercle::Traslation(const Vecteur2D v)
{
	return FormeGeometriqueSimple::Traslation(v);
}
int Cercle::Homothetie()
{
	return 0;
}
int Cercle::Rotation(const Vecteur2D v, int angle)
{
	return FormeGeometriqueSimple::Rotation(v, angle);
}

const Cercle & Cercle::operator=(const Cercle & c)
{
	if (this != &c) {
		this->setColor(c.getColor());
		this->_vecteurOrigine = c._vecteurOrigine;
		this->_rayon = c._rayon;
	}
	return *this;
}

ostream & operator<<(ostream &os, const Cercle &c)
{
	FormeGeometriqueSimple var = c;
	return os << "Cercle [" << var << ", rayon: " << c._rayon << "]";
}