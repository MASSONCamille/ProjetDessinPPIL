#pragma once
#include "FormeGeometriqueSimple.h"


class Cercle : public FormeGeometriqueSimple
{
private:
	double _rayon;

protected:

public:
	inline Cercle()
		: FormeGeometriqueSimple()
	{
		this->_rayon = 0;
	}
	inline Cercle(const Cercle & c)
		: FormeGeometriqueSimple(c._color, c._vecteurOrigine)
	{
		this->_rayon = c._rayon;
	}
	inline Cercle(const Couleurs c, const Vecteur2D v, const double r)
		: FormeGeometriqueSimple(c, v)
	{
		this->_rayon = r;
	}

	virtual ~Cercle();

	inline double getRayon() const
	{
		return this->_rayon;
	}
	inline void setRayon(const double r)
	{
		this->_rayon = r;
	}

	int Dessiner() const;
	int Traslation() const;
	int Homothetie() const;
	int Rotation() const;

	const Cercle & operator = (const Cercle &);
};