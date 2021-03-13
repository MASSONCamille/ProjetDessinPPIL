#pragma once

#include "Charger.h"

class ChargerCOR : public Charger
{
public:
	ChargerCOR* suivant;

protected:
	ChargerCOR(ChargerCOR* suivant);

	virtual const char* charger1(string nomFichier, string forme) const = 0;

public:

	const char* charger(string nomFichier, string forme) const;

};