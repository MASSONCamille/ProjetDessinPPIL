#pragma once

#include "Charger.h"
#include "ChargerCOR.h"
#include "ChargerSegmentTxt.h"

class DictionnaireCharger {

private:

	ChargerCOR* _chargerDebut;

public:

	DictionnaireCharger();

	const ChargerCOR* getCharger() const;

};
