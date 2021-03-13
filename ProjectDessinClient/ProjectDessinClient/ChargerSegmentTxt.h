#pragma once

#include "ChargerCOR.h"

class ChargerSegmentTxt : public ChargerCOR
{

public:

	ChargerSegmentTxt(ChargerCOR* suivant);

protected:

	const char* charger1(string nomFichier, string forme) const;
};
