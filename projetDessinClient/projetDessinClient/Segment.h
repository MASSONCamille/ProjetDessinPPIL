#pragma once

#include "FormeGeometriqueSimple.h"

class Segment : public FormeGeometriqueSimple
{
private:
	Vecteur2D _point;	// vecteur qui donne la direction et longeur
						// donc qui donne le point ou fini le segment

public:
	inline Segment()
		: FormeGeometriqueSimple()
	{
		this->_point = Vecteur2D();
	}
	inline Segment(const Segment & s)
		: FormeGeometriqueSimple(s.getColor(), s._vecteurOrigine)
	{
		this->_point = s._point;
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
	int Traslation(const Vecteur2D);
	int Homothetie();
	int Rotation(const Vecteur2D, int);

	virtual int Save(const VisitorSauvg *) const;

	const Segment & operator = (const Segment &);

	friend ostream& operator<<(ostream&, const Segment&);

	const string to_string() const;
};

extern ostream& operator<<(ostream&, const Segment&);

