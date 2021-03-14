#pragma once

#include "ChargerCOR.h"

class ChargerCroixTxt : public ChargerCOR
{

public:

	ChargerCroixTxt(ChargerCOR* suivant);

protected:

	FormeGeometriqueBase* charger1(string nomFichier, string forme) const;
};
