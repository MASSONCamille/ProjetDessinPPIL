#include "Vecteur2D.h"


Vecteur2D::~Vecteur2D()
{
}


Vecteur2D Vecteur2D::rota(const int tau)
{
	double a = this->_x, b = this->_y;
	this->_x = (cos(tau*M_PI / 180) * a) - (sin(tau*M_PI / 180) * b);
	this->_y = (sin(tau*M_PI / 180) * a) + (cos(tau*M_PI / 180) * b);

	return *this;
}

const Vecteur2D & Vecteur2D::operator=(const Vecteur2D & v)
{
	if (this != &v) {
		this->_x = v._x;
		this->_y = v._y;
	}
	return *this;
}
Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(_x + u._x, _y + u._y);
}
Vecteur2D Vecteur2D::operator - (const Vecteur2D & u) const
{
	return Vecteur2D(_x - u._x, _y - u._y);
}
Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(_x*a, _y*a);
}
Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_x, -_y);
}

ostream & operator<<(ostream &os, const Vecteur2D &v)
{
	return os << v.getX() << "|" << v.getY();
}

const string Vecteur2D::to_string() const {
	return "x=" + std::to_string(this->_x) + " | y=" + std::to_string(this->_y);
}
