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
int FormeGeometriqueSimple::Rotation(const Vecteur2D v, int angle)
{
	angle = FormeGeometriqueBase::Rotation(v, angle);
	return angle;
}

