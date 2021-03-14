#pragma once

#include "FormeGeometriqueBase.h"
#include "FormeGeometriqueSimple.h"
#include <vector>

class FormeGeometriqueCompose : public FormeGeometriqueBase
{
private:
	vector<FormeGeometriqueSimple*> _listForme;
	int _nbForme;

public:

	inline FormeGeometriqueCompose()
		: FormeGeometriqueBase()
	{
		this->_nbForme = 0;
		this->_listForme = vector<FormeGeometriqueSimple*>();
	}
	inline FormeGeometriqueCompose(const Couleurs c, const int nbf)
		: FormeGeometriqueBase(c)
	{
		this->_listForme = vector<FormeGeometriqueSimple*>();
		this->_nbForme = nbf;
	}
	inline FormeGeometriqueCompose(const FormeGeometriqueCompose & f)
		: FormeGeometriqueBase(f.getColor())
	{
		this->_listForme = f._listForme;
		this->_nbForme = f._nbForme;
	}

	virtual ~FormeGeometriqueCompose() {}

	inline int getNbForme() const
	{
		return this->_nbForme;
	}
	inline vector<FormeGeometriqueSimple*> getListForme() const
	{
		return this->_listForme;
	}
	inline void setListForme(const vector<FormeGeometriqueSimple*> lf)
	{
		this->_nbForme = lf.size();
		this->_listForme = lf;
		for (int i = 0; i < this->_nbForme; i++)
			this->_listForme[i]->setColor(this->getColor());

	}
	inline void addForme(FormeGeometriqueSimple* f)
	{
		f->setColor(this->getColor());
		vector<FormeGeometriqueSimple*>::iterator it = this->_listForme.begin();
		this->_listForme.insert(it, f);
	}

	virtual int Dessiner(const Fenetre *, const VisitorDessin *) const;
	int Traslation(const Vecteur2D);
	int Homothetie();
	int Rotation(const Vecteur2D, int);

	const FormeGeometriqueCompose & operator = (const FormeGeometriqueCompose &);

	friend ostream& operator<<(ostream&, const FormeGeometriqueCompose&);

	const string to_string() const;
};

extern ostream& operator<<(ostream&, const FormeGeometriqueCompose&);
