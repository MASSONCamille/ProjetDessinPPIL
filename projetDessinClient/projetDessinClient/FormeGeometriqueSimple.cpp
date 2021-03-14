#include "FormeGeometriqueSimple.h"


int FormeGeometriqueSimple::Traslation(const Vecteur2D v)
{
	this->setVec(this->getVec() + v);
	return 0;
}
int FormeGeometriqueSimple::Homothetie()
{
	return 0;
}
int FormeGeometriqueSimple::Rotation(const Vecteur2D vr, int angle)
{
	angle = FormeGeometriqueBase::Rotation(vr, angle);
	this->_vecteurOrigine = vr + (this->_vecteurOrigine - vr).rota(angle);
	return 0;
}

ostream & operator<<(ostream &os, const FormeGeometriqueSimple &f)
{
	FormeGeometriqueBase var = f;
	return os << var << ", origin: " << f._vecteurOrigine;
}
