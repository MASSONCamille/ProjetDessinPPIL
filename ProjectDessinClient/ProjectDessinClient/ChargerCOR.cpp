#include "ChargerCOR.h"

ChargerCOR::ChargerCOR(ChargerCOR* suivant) : suivant(suivant) {}

FormeGeometriqueBase* ChargerCOR::charger(string nomFichier, string forme) const
{
    FormeGeometriqueBase* resultat;
    resultat = this->charger1(nomFichier, forme);

    if (resultat != nullptr)
        return resultat;

    else

        if (this->suivant != nullptr)
            return this->suivant->charger(nomFichier, forme);
        else
            return nullptr;
}
