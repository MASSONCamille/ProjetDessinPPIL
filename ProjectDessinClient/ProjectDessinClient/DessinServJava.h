#pragma once

#include "VisitorDessin.h"
#include "Client.h"


class DessinServJava : public VisitorDessin
{
	int Dessiner(const Fenetre *, const Cercle *) const;
	int Dessiner(const Fenetre *, const Croix *) const;
	int Dessiner(const Fenetre *) const;
	int Effacer(const Fenetre *) const;
};

