#include "ChargerCercleTxt.h"
#include "Cercle.h"
#include <regex>
#include <fstream>

ChargerCercleTxt::ChargerCercleTxt(ChargerCOR* suivant) : ChargerCOR(suivant) {}

FormeGeometriqueBase* ChargerCercleTxt::charger1(string nomFichier, string forme) const
{
    if (regex_match(nomFichier, regex("(\\w+).txt$")) && forme == "cercle") {
        string ligne;
        ifstream fichier;
        fichier.open("../Sauvegardes/" + nomFichier);
        if (fichier.good()) {
            if (getline(fichier, ligne)) {
                int pos = 0;
                int i = 0;
                string delimiter = "/";
                string donnees[4];
                while ((pos = ligne.find(delimiter)) != string::npos && i < 4) {
                    donnees[i] = ligne.substr(0, pos);
                    ligne.erase(0, pos + delimiter.length());
                    i++;
                }
                return new Cercle((FormeGeometriqueBase::Couleurs)stoi(donnees[0]), Vecteur2D(stod(donnees[1]), stod(donnees[2])), stoi(donnees[3]));
            }
        }
        fichier.close();
    }

    return nullptr;
}