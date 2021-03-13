#pragma once
#include "FormeGeometriqueSimple.h"


class Cercle : public FormeGeometriqueSimple
{
private:
	double _rayon;

public:
	inline Cercle()
		: FormeGeometriqueSimple()
	{
		this->_rayon = 0;
	}
	inline Cercle(const Cercle & c)
		: FormeGeometriqueSimple(c.getColor(), c._vecteurOrigine)
	{
		this->_rayon = c._rayon;
	}
	inline Cercle(const Couleurs c, const Vecteur2D v, const double r)
		: FormeGeometriqueSimple(c, v)
	{
		this->_rayon = r;
	}

	virtual ~Cercle() {};

	inline double getRayon() const
	{
		return this->_rayon;
	}
	inline void setRayon(const double r)
	{
		this->_rayon = r;
	}

	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const;
	int Traslation();
	int Homothetie();
	int Rotation();

	const Cercle & operator = (const Cercle &);
};