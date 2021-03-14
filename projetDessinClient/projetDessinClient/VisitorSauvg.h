#pragma once

#include "Cercle.h"
#include "Croix.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"

class VisitorSauvg
{
public:
	virtual int Sauvgarde(const Cercle *) const = 0;
	virtual int Sauvgarde(const Croix *) const = 0;
	virtual int Sauvgarde(const Segment *) const = 0;
	virtual int Sauvgarde(const Polygone *) const = 0;
	virtual int Sauvgarde(const Triangle *) const = 0;
};
