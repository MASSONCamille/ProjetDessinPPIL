#pragma once

#include "VisitorSauvg.h"
#include <fstream>

class SauvgTxt : public VisitorSauvg
{
	int Sauvgarde(const Cercle *) const;
	int Sauvgarde(const Croix *) const;
	int Sauvgarde(const Segment *) const;
	int Sauvgarde(const Polygone *) const;
	int Sauvgarde(const Triangle *) const;
};

