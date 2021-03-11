#pragma once

#include "FormeGeometriqueBase.h"
#include "FormeGeometriqueSimple.h"
#include "Cercle.h"
#include "Croix.h"
#include "Fenetre.h"

class VisitorDessin
{
public:
	virtual int Dessiner(const Fenetre *, const Cercle *) const = 0;
	virtual int Dessiner(const Fenetre *, const Croix *) const = 0;
	virtual int Dessiner(const Fenetre *) const = 0;
	virtual int Effacer(const Fenetre *) const = 0;

			//paterne pour l'ajout d'un visitor sur une classe :
	//virtual int Dessiner(const Classe * varClasse) const = 0;
};

