#pragma once
#include "FormeGeometriqueSimple.h"

class Croix : public FormeGeometriqueSimple
{
private:
	Vecteur2D _diagonale;

public:
	inline Croix()
		: FormeGeometriqueSimple()
	{
		this->_diagonale = Vecteur2D();
	}
	inline Croix(const Croix & c)
		: FormeGeometriqueSimple(c.getColor(), c._vecteurOrigine)
	{
		this->_diagonale = c._diagonale;
	}
	inline Croix(const Couleurs c, const Vecteur2D v, const Vecteur2D d)
		: FormeGeometriqueSimple(c, v)
	{
		this->_diagonale = d;
	}

	virtual ~Croix(){}

	inline Vecteur2D getDiagonale() const
	{
		return this->_diagonale;
	}
	inline void setDiagonale(const Vecteur2D d)
	{
		this->_diagonale = d;
	}

	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const;
	int Traslation();
	int Homothetie();
	int Rotation();

	const Croix & operator = (const Croix &);

};

