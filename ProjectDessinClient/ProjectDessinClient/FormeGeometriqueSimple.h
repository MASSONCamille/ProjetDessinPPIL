#pragma once
#include "FormeGeometriqueBase.h"
#include "Vecteur2D.h"

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

	virtual int Dessiner() const;
	virtual int Traslation() const;
	virtual int Homothetie() const;
	virtual int Rotation() const;

public:
	virtual ~FormeGeometriqueSimple();

	inline Vecteur2D getVec() const
	{
		return this->_vecteurOrigine;
	}
	inline void setVec(const Vecteur2D v)
	{
		this->_vecteurOrigine = v;
	}


};

