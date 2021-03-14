#pragma once
#include "FormeGeometriqueBase.h"

class FormeGeometriqueSimple : public FormeGeometriqueBase
{
protected:
	Vecteur2D _vecteurOrigine;

	inline FormeGeometriqueSimple()
		: FormeGeometriqueBase()
	{
		this->_vecteurOrigine = Vecteur2D();
	}
	inline FormeGeometriqueSimple(const Couleurs c, const Vecteur2D v)
		: FormeGeometriqueBase(c)
	{
		this->_vecteurOrigine = v;
	}

public:
	virtual ~FormeGeometriqueSimple() {};

	inline Vecteur2D getVec() const
	{
		return this->_vecteurOrigine;
	}
	inline void setVec(const Vecteur2D v)
	{
		this->_vecteurOrigine = v;
	}

	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const { return 0; };
	virtual int Traslation(const Vecteur2D);
	virtual int Homothetie();
	virtual int Rotation(const Vecteur2D, int);

	friend ostream& operator<<(ostream&, const FormeGeometriqueSimple&);

	virtual const string to_string() const;
};

extern ostream& operator<<(ostream&, const FormeGeometriqueSimple &);