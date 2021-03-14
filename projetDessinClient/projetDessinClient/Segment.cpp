#include "Segment.h"
#include "VisitorDessin.h"
#include "VisitorSauvg.h"


int Segment::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Segment::Traslation(const Vecteur2D v)
{
	return FormeGeometriqueSimple::Traslation(v);
}
int Segment::Homothetie()
{
	return 0;
}
int Segment::Rotation(const Vecteur2D vr, int angle)
{
	Vecteur2D vo = this->_vecteurOrigine;

	if (FormeGeometriqueSimple::Rotation(vr, angle)) return 1;
	this->_point =
		(vo - vr + this->_point).rota(angle)
		+ vr - this->_vecteurOrigine;

	return 0;
}

int Segment::Save(const VisitorSauvg *v) const
{
	return v->Sauvgarde(this);
}

const Segment & Segment::operator=(const Segment & s)
{
	if (this != &s) {
		this->setColor(s.getColor());
		this->_vecteurOrigine = s._vecteurOrigine;
		this->_point = s._point;
	}
	return *this;
}

ostream & operator<<(ostream &os, const Segment &s)
{
	FormeGeometriqueSimple var = s;
	return os << "Segment [" << var << ", vecteurPoint: " << s._point << "]";
}

const string Segment::to_string() const {
	return "Segment: [" + FormeGeometriqueSimple::to_string() + ", Point: " + this->_point.to_string() + "]";
}