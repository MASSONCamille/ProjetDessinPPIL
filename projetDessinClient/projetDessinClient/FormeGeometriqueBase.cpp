#include "FormeGeometriqueBase.h"

const char* FormeGeometriqueBase::couleurs_str[6] = {
	 "Black",
	 "Blue",
	 "Red",
	 "Green",
	 "Yellow",
	 "Cyan"
};

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

const string FormeGeometriqueBase::to_string() const {
	return "Couleur: " + (string)this->couleurs_str[this->_color];
}