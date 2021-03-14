#pragma once

#include "Fenetre.h"
#include "Vecteur2D.h"


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

	static const char* couleurs_str[6];

	inline FormeGeometriqueBase()
	{
		this->_color = BLACK;
	}
	inline FormeGeometriqueBase(const Couleurs c)
	{
		this->_color = c;
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

	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const { return 0; };
	virtual int Traslation(const Vecteur2D);
	virtual int Homothetie();
	virtual int Rotation(const Vecteur2D, int);

	friend ostream& operator<<(ostream&, const FormeGeometriqueBase&);

	const string to_string() const;

private:
	Couleurs _color;
};

extern ostream& operator<<(ostream&, const FormeGeometriqueBase &);

