#include "Polygone.h"
#include "VisitorDessin.h"
#include "VisitorSauvg.h"


int Polygone::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Polygone::Traslation(const Vecteur2D v)
{
	return FormeGeometriqueSimple::Traslation(v);
}
int Polygone::Homothetie()
{
	return 0;
}
int Polygone::Rotation(const Vecteur2D vr, int angle)
{
	Vecteur2D vo = this->_vecteurOrigine;

	if (FormeGeometriqueSimple::Rotation(vr, angle)) return 1;

	int i = 0;
	for (Vecteur2D vn : this->_listPoint) {
		this->_listPoint[i] = (vo - vr + vn).rota(angle) + vr - this->_vecteurOrigine;
		i++;
	}

	return 0;
}

int Polygone::Save(const VisitorSauvg *v) const
{
	return v->Sauvgarde(this);
}

const Polygone & Polygone::operator=(const Polygone & p)
{
	if (this != &p) {
		this->setColor(p.getColor());
		this->_vecteurOrigine = p._vecteurOrigine;
		this->_nbPoint = p._nbPoint;
		this->_listPoint = p._listPoint;
	}
	return *this;
}

ostream & operator<<(ostream &os, const Polygone &p)
{
	FormeGeometriqueSimple var = p;
	os << "Polygone [" << var << ", NBpoint: " << p._nbPoint << endl << "\t, listPoints: [ ";
	for (Vecteur2D v : p._listPoint)
		os << v << " ";

	return os << "]" << endl << "]";
}

const string Polygone::to_string() const {
	string message = "Polygone: [" + FormeGeometriqueSimple::to_string() + ", Nombre de point: " + std::to_string(this->_nbPoint) + "\n";
	int i = 2;
	for (Vecteur2D v : this->_listPoint) {
		message += ("Point" + std::to_string(i) +": " + v.to_string() + "\n");
		i++;
	}
	message += "]";
	return message;
}