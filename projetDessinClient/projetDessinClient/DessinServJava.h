#pragma once

#include "VisitorDessin.h"
#include "Client.h"


class DessinServJava : public VisitorDessin
{
	int Dessiner(const Fenetre *, const Cercle *) const;
	int Dessiner(const Fenetre *, const Croix *) const;
	int Dessiner(const Fenetre *, const Segment *) const;
	int Dessiner(const Fenetre *, const Polygone *) const;
	int Dessiner(const Fenetre *, const Triangle *) const;

	int Afficher(const Fenetre *) const;
	int Effacer(const Fenetre *) const;
	int Detruire(const Fenetre *) const;
};

