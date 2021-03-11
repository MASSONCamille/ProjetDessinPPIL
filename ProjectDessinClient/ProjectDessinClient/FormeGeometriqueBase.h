#pragma once

#include "Fenetre.h"


class VisitorDessin;

class FormeGeometriqueBase
{
public:
	enum Couleurs {
		BLACK = 0,
		BLUE = 1,
		RED = 2,
		GREEN = 3,
		YELLOW = 4,
		CYAN = 5
	};

	inline FormeGeometriqueBase()
	{
		this->_color = BLACK;
	}

	virtual ~FormeGeometriqueBase() {};

	inline Couleurs getColor() const
	{
		return this->_color;
	}
	inline void setColor(const Couleurs c)
	{
		this->_color = c;
	}

	inline FormeGeometriqueBase(const Couleurs c)
	{
		this->_color = c;
	}

	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const = 0;
	virtual int Traslation();
	virtual int Homothetie();
	virtual int Rotation();

private:
	Couleurs _color;
};

