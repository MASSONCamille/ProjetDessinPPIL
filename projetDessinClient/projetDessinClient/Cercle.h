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
	int Traslation(const Vecteur2D);
	int Homothetie();
	int Rotation(const Vecteur2D, int);

	virtual int Save(const VisitorSauvg *) const;

	const Cercle & operator = (const Cercle &);

	friend ostream& operator<<(ostream&, const Cercle&);
	
	const string to_string() const;
};

extern ostream& operator<<(ostream&, const Cercle&);