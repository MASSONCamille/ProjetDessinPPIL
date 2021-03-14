#pragma once

#include "FormeGeometriqueSimple.h"
#include <vector>


class Polygone : public FormeGeometriqueSimple
{
private:
	int _nbPoint;
	vector<Vecteur2D> _listPoint;

public:
	inline Polygone()
		: FormeGeometriqueSimple()
	{
		this->_nbPoint = 0;
		this->_listPoint = vector<Vecteur2D>();
	}
	inline Polygone(const Polygone & p)
		: FormeGeometriqueSimple(p.getColor(), p._vecteurOrigine)
	{
		this->_nbPoint = p._nbPoint;
		this->_listPoint = p._listPoint;
	}
	inline Polygone(const Couleurs c, const Vecteur2D v, const int nbp)
		: FormeGeometriqueSimple(c, v)
	{
		this->_nbPoint = nbp;
		this->_listPoint = vector<Vecteur2D>();
	}

	virtual ~Polygone() {}

	inline int getNbPoint() const
	{
		return this->_nbPoint;
	}
	inline void setNbPoint(int nbp)
	{
		this->_nbPoint = nbp;
	}
	inline vector<Vecteur2D> getListPoint() const
	{
		return this->_listPoint;
	}
	inline void setListPoint(vector<Vecteur2D> lp)
	{
		this->_listPoint = lp;
	}


	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const;
	int Traslation(const Vecteur2D);
	int Homothetie();
	int Rotation(const Vecteur2D, int);

	const Polygone & operator = (const Polygone &);

	friend ostream& operator<<(ostream&, const Polygone&);

	const string to_string() const;
};

extern ostream& operator<<(ostream&, const Polygone&);

