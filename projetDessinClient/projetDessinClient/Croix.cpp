#include "Croix.h"
#include "VisitorDessin.h"


int Croix::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int Croix::Traslation(const Vecteur2D v)
{
	return FormeGeometriqueSimple::Traslation(v);
}
int Croix::Homothetie()
{
	return 0;
}
int Croix::Rotation(const Vecteur2D vr, int angle)
{
	Vecteur2D vo = this->_vecteurOrigine;

	if (FormeGeometriqueSimple::Rotation(vr, angle)) return 1;
	this->_diagonale =
		( vo - vr + this->_diagonale ).rota(angle)
		+ vr - this->_vecteurOrigine;

	return 0;
}

const Croix & Croix::operator=(const Croix & c)
{
	if (this != &c) {
		this->setColor(c.getColor());
		this->_vecteurOrigine = c._vecteurOrigine;
		this->_diagonale = c._diagonale;
	}
	return *this;
}

ostream & operator<<(ostream &os, const Croix &c)
{
	FormeGeometriqueSimple var = c;
	return os << "Croix [" << var << ", diagonale: " << c._diagonale << "]";
}

const string Croix::to_string() const {
	return "Croix: [" + FormeGeometriqueSimple::to_string() + ", Diagonale: " + this->_diagonale.to_string() + "]";
}