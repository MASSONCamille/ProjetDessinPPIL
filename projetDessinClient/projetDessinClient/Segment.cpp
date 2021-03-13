#include "Segment.h"
#include "VisitorDessin.h"


int Segment::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Segment::Traslation()
{
	return 0;
}
int Segment::Homothetie()
{
	return 0;
}
int Segment::Rotation()
{
	return 0;
}

const Segment & Segment::operator=(const Segment & c)
{
	if (this != &c) {
		this->setColor(c.getColor());
		this->_vecteurOrigine = c._vecteurOrigine;
		this->_point = this->_point;
	}
	return *this;
}