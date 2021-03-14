#include "DictionnaireCharger.h"
#include "ChargerCercleTxt.h"
#include "ChargerCroixTxt.h"
#include "ChargerPolygoneTxt.h"
#include "ChargerSegmentTxt.h"
#include "ChargerTriangleTxt.h"

DictionnaireCharger::DictionnaireCharger() {

	ChargerCOR* chargerCercleTxt = new ChargerCercleTxt(nullptr);
	ChargerCOR* chargerCroixTxt = new ChargerCroixTxt(chargerCercleTxt);
	ChargerCOR* chargerPolygoneTxt = new ChargerPolygoneTxt(chargerCroixTxt);
	ChargerCOR* chargerSegmentTxt = new ChargerSegmentTxt(chargerPolygoneTxt);
	ChargerCOR* chargerTriangleTxt = new ChargerTriangleTxt(chargerSegmentTxt);

	_chargerDebut = chargerTriangleTxt;
}


const ChargerCOR* DictionnaireCharger::getCharger() const {
	return _chargerDebut;
}