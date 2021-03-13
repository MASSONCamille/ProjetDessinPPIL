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
int FormeGeometriqueSimple::Rotation()
{
	return 0;
}

