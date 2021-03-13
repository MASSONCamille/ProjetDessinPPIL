#include "ChargerSegmentTxt.h"
#include <string.h>

ChargerSegmentTxt::ChargerSegmentTxt(ChargerCOR* suivant) : ChargerCOR(suivant) {}

const char* ChargerSegmentTxt::charger1(string nomFichier, string forme) const
{
    if (nomFichier.compare("test") == 0 && forme.compare("croix") == 0)
        return "ok";

    return nullptr;
}