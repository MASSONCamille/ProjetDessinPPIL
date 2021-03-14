#pragma once

#include "Charger.h"

class ChargerCOR : public Charger
{
public:
	ChargerCOR* suivant;

protected:
	ChargerCOR(ChargerCOR* suivant);

	virtual FormeGeometriqueBase* charger1(string nomFichier, string forme) const = 0;

public:

	FormeGeometriqueBase* charger(string nomFichier, string forme) const;

};