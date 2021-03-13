#include "Triangle.h"
#include "VisitorDessin.h"


int Triangle::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Triangle::Traslation()
{
	return 0;
}
int Triangle::Homothetie()
{
	return 0;
}
int Triangle::Rotation()
{
	return 0;
}

const Triangle & Triangle::operator=(const Triangle & t)
{
	if (this != &t) {
		this->setColor(t.getColor());
		this->_vecteurOrigine = t._vecteurOrigine;
		this->_p2 = t._p2;
		this->_p3 = t._p3;
	}
	return *this;
}