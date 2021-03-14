#include "Polygone.h"
#include "VisitorDessin.h"


int Polygone::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Polygone::Traslation(const Vecteur2D v)
{
	return FormeGeometriqueSimple::Traslation(v);
}
int Polygone::Homothetie()
{
	return 0;
}
int Polygone::Rotation(const Vecteur2D vr, int angle)
{
	Vecteur2D vo = this->_vecteurOrigine;

	if (FormeGeometriqueSimple::Rotation(vr, angle)) return 1;

	int i = 0;
	for (Vecteur2D vn : this->_listPoint) {
		this->_listPoint[i] = (vo - vr + vn).rota(angle) + vr - this->_vecteurOrigine;
		i++;
	}

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

ostream & operator<<(ostream &os, const Polygone &p)
{
	FormeGeometriqueSimple var = p;
	os << "Polygone [" << var << ", NBpoint: " << p._nbPoint << endl << "\t, listPoints: [ ";
	for (Vecteur2D v : p._listPoint)
		os << v << " ";

	return os << "]" << endl << "]";
}