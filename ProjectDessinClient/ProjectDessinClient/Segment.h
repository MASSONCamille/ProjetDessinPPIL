#pragma once
#include "FormeGeometriqueSimple.h"


class Segment : public FormeGeometriqueSimple
{
private:
	Vecteur2D _point;

public:
	inline Segment()
		: FormeGeometriqueSimple()
	{
		this->_point = Vecteur2D();
	}
	inline Segment(const Segment & c)
		: FormeGeometriqueSimple(c.getColor(), c._vecteurOrigine)
	{
		this->_point = c._point;
	}
	inline Segment(const Couleurs c, const Vecteur2D v, const Vecteur2D p)
		: FormeGeometriqueSimple(c, v)
	{
		this->_point = p;
	}

	virtual ~Segment() {};

	inline Vecteur2D getPoint() const
	{
		return this->_point;
	}
	inline void setPoint(const Vecteur2D p)
	{
		this->_point = p;
	}

	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const;
	int Traslation();
	int Homothetie();
	int Rotation();

	const Segment & operator = (const Segment &);
};

