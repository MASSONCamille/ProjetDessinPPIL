#include "FormeGeometriqueBase.h"


int FormeGeometriqueBase::Traslation(const Vecteur2D)
{
	return 0;
}
int FormeGeometriqueBase::Homothetie()
{
	return 0;
}
int FormeGeometriqueBase::Rotation(const Vecteur2D v, int angle)
{
	return angle % 360;
}

ostream & operator<<(ostream &os, const FormeGeometriqueBase &f)
{
	return os << "color: " << f._color;
}