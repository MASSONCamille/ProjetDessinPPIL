#include "Triangle.h"
#include "VisitorDessin.h"


int Triangle::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Triangle::Traslation(const Vecteur2D v)
{
	return FormeGeometriqueSimple::Traslation(v);
}
int Triangle::Homothetie()
{
	return 0;
}
int Triangle::Rotation(const Vecteur2D vr, int angle)
{
	Vecteur2D vo = this->_vecteurOrigine;

	if (FormeGeometriqueSimple::Rotation(vr, angle)) return 1;
	this->_p2 = (vo - vr + this->_p2).rota(angle) + vr - this->_vecteurOrigine;
	this->_p3 = (vo - vr + this->_p3).rota(angle) + vr - this->_vecteurOrigine;

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

ostream & operator<<(ostream &os, const Triangle &t)
{
	FormeGeometriqueSimple var = t;
	return os << "Triangle [" << var << ", vectPoint2: " << t._p2 << ", vectPoint3: " << t._p3 << "]";
}

const string Triangle::to_string() const {
	return "Triangle: [" + FormeGeometriqueSimple::to_string() + ", Point2: " + this->_p2.to_string() + ", Point3: " + this->_p3.to_string() + "]";
}