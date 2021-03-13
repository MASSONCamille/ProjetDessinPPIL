#include "Vecteur2D.h"

using namespace std;


Vecteur2D::~Vecteur2D()
{
}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(_x + u._x, _y + u._y);
}
const Vecteur2D Vecteur2D::operator - (const Vecteur2D & u) const
{
	return Vecteur2D(_x - u._x, _y - u._y);
}
const Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(_x*a, _y*a);
}
const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_x, -_y);
}
