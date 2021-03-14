#pragma once

#include "ChargerCOR.h"

class ChargerCercleTxt : public ChargerCOR
{

public:

	ChargerCercleTxt(ChargerCOR* suivant);

protected:

	FormeGeometriqueBase* charger1(string nomFichier, string forme) const;
};