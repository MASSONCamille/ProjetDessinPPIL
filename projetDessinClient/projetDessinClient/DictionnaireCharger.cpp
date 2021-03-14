#include "DictionnaireCharger.h"

DictionnaireCharger::DictionnaireCharger() {

	ChargerCOR* chargerSegmentTxt = new ChargerSegmentTxt(nullptr);

	_chargerDebut = chargerSegmentTxt;
}


const ChargerCOR* DictionnaireCharger::getCharger() const {
	return _chargerDebut;
}