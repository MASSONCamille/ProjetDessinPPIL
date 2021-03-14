#pragma once

#include "ChargerCOR.h"

class ChargerPolygoneTxt : public ChargerCOR
{

public:

	ChargerPolygoneTxt(ChargerCOR* suivant);

protected:

	FormeGeometriqueBase* charger1(string nomFichier, string forme) const;
};
