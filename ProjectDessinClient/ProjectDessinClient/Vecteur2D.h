#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Vecteur2D
{
private:
	double _x, _y;


public:
	inline Vecteur2D()
	{
		this->_x = 0;
		this->_y = 0;
	}
	inline Vecteur2D(const double x, const double y)
	{
		this->_x = x;
		this->_y = y;
	}

	virtual ~Vecteur2D();

	inline double getX() const
	{
		return this->_x;
	}
	inline double getY() const
	{
		return this->_y;
	}
	inline void setX(const double x)
	{
		this->_x = x;
	}
	inline void setY(const double y)
	{
		this->_y = y;
	}


	const Vecteur2D operator + (const Vecteur2D & u) const;
	const Vecteur2D operator * (const double & a) const;
	const Vecteur2D operator - () const;
};

