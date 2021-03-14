#include "ChargerSegmentTxt.h"
#include "Segment.h"
#include <regex>
#include <fstream>

ChargerSegmentTxt::ChargerSegmentTxt(ChargerCOR* suivant) : ChargerCOR(suivant) {}

FormeGeometriqueBase* ChargerSegmentTxt::charger1(string nomFichier, string forme) const
{
    if (regex_match(nomFichier, regex("(\\w+).txt$")) && forme == "segment") {
        string ligne;
        ifstream fichier;
        fichier.open("../Sauvegardes/" + nomFichier);
        if (fichier.good()) {
            if (getline(fichier, ligne)) {
                int pos = 0;
                int i = 0;
                string delimiter = "/";
                string donnees[5];
                while ((pos = ligne.find(delimiter)) != string::npos && i < 3) {
                    donnees[i] = ligne.substr(0, pos);
                    ligne.erase(0, pos + delimiter.length());
                    i++;
                }
                return new Segment(FormeGeometriqueBase::Couleurs(stoi(donnees[0])), Vecteur2D(stoi(donnees[1]), stoi(donnees[2])), Vecteur2D(stoi(donnees[3]), stoi(donnees[4])));
            }
        }
        fichier.close();
    }

    return nullptr;
}