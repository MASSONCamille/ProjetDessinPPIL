#include "FormeGeometriqueCompose.h"
#include "VisitorDessin.h"


int FormeGeometriqueCompose::Dessiner(const Fenetre * f, const VisitorDessin * v) const
{
	return v->Dessiner(f, this);
}
int FormeGeometriqueCompose::Traslation(const Vecteur2D v)
{
	for (int i = 0; i < this->_nbForme; i++) {
		if (this->_listForme[i]->Traslation(v)) return 1;
	}
	return 0;
}
int FormeGeometriqueCompose::Homothetie()
{
	return 0;
}
int FormeGeometriqueCompose::Rotation(const Vecteur2D vr, int angle)
{
	for (int i = 0; i < this->_nbForme; i++) {
		if (this->_listForme[i]->Rotation(vr, angle)) return 1;
	}
	return 0;
}

const FormeGeometriqueCompose & FormeGeometriqueCompose::operator=(const FormeGeometriqueCompose & f)
{
	if (this != &f) {
		this->setColor(f.getColor());
		this->_listForme = f._listForme;
		this->_nbForme = f._nbForme;
	}
	return *this;
}

ostream & operator<<(ostream &os, const FormeGeometriqueCompose &f)
{
	FormeGeometriqueBase var = f;
	os << "FormeGeometriqueCompose [" << var << ", NBforme: " << f._nbForme << endl << "\t, listFrome: [ " << endl;
	for (FormeGeometriqueSimple * fs : f._listForme)
		os << fs->to_string() << endl;

	return os << "\t]" << endl << "]";
}

const string FormeGeometriqueCompose::to_string() const {
	string message = "FormeGeometriqueCompose: [" + FormeGeometriqueBase::to_string() + ", Nombre de forme: " + std::to_string(this->_nbForme) + "\n";
	int i = 1;
	for (FormeGeometriqueSimple * fs : this->_listForme) {
		message += ("Forme" + std::to_string(i) + ": " + fs->to_string() + "\n");
		i++;
	}
	message += "]";
	return message;
}