#pragma once

#include "Cercle.h"
#include "Croix.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"

#include "Fenetre.h"

class VisitorDessin
{
public:
	virtual int Dessiner(const Fenetre *, const Cercle *) const = 0;
	virtual int Dessiner(const Fenetre *, const Croix *) const = 0;
	virtual int Dessiner(const Fenetre *, const Segment *) const = 0;
	virtual int Dessiner(const Fenetre *, const Polygone *) const = 0;
	virtual int Dessiner(const Fenetre *, const Triangle *) const = 0;

	virtual int Afficher(const Fenetre *) const = 0;
	virtual int Effacer(const Fenetre *) const = 0;
	virtual int Detruire(const Fenetre *) const = 0;
};

