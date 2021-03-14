#pragma once

#include "FormeGeometriqueSimple.h"


class Triangle : public FormeGeometriqueSimple
{
private:
	Vecteur2D _p2, _p3;

public:
	inline Triangle()
		: FormeGeometriqueSimple()
	{
		this->_p2 = Vecteur2D();
		this->_p3 = Vecteur2D();
	}
	inline Triangle(const Triangle & t)
		: FormeGeometriqueSimple(t.getColor(), t._vecteurOrigine)
	{
		this->_p2 = t._p2;
		this->_p3 = t._p3;
	}
	inline Triangle(const Couleurs c, const Vecteur2D v, const Vecteur2D v2, const Vecteur2D v3)
		: FormeGeometriqueSimple(c, v)
	{
		this->_p2 = v2;
		this->_p3 = v3;
	}

	virtual ~Triangle() {}

	inline Vecteur2D getP2() const
	{
		return this->_p2;
	}
	inline void setP2(Vecteur2D v)
	{
		this->_p2 = v;
	}
	inline Vecteur2D getP3() const
	{
		return this->_p3;
	}
	inline void setP3(Vecteur2D v)
	{
		this->_p3 = v;
	}


	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const;
	int Traslation(const Vecteur2D);
	int Homothetie();
	int Rotation(const Vecteur2D, int);

	virtual int Save(const VisitorSauvg *) const;

	const Triangle & operator = (const Triangle &);

	friend ostream& operator<<(ostream&, const Triangle&);

	const string to_string() const;
};

extern ostream& operator<<(ostream&, const Triangle&);




