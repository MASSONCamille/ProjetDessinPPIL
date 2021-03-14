#pragma once

#include "ChargerCOR.h"

class ChargerTriangleTxt : public ChargerCOR
{

public:

	ChargerTriangleTxt(ChargerCOR* suivant);

protected:

	FormeGeometriqueBase* charger1(string nomFichier, string forme) const;
};
