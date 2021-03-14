#include "ChargerTriangleTxt.h"
#include "Triangle.h"
#include <regex>
#include <fstream>

ChargerTriangleTxt::ChargerTriangleTxt(ChargerCOR* suivant) : ChargerCOR(suivant) {}

FormeGeometriqueBase* ChargerTriangleTxt::charger1(string nomFichier, string forme) const
{
    if (regex_match(nomFichier, regex("(\\w+).txt$")) && forme == "triangle") {
        string ligne;
        ifstream fichier;
        fichier.open("../Sauvegardes/" + nomFichier);
        if (fichier.good()) {
            if (getline(fichier, ligne)) {
                int pos = 0;
                int i = 0;
                string delimiter = "/";
                string donnees[7];
                while ((pos = ligne.find(delimiter)) != string::npos && i < 7) {
                    donnees[i] = ligne.substr(0, pos);
                    ligne.erase(0, pos + delimiter.length());
                    i++;
                }
                return new Triangle((FormeGeometriqueBase::Couleurs)stoi(donnees[0]), Vecteur2D(stod(donnees[1]), stod(donnees[2])), Vecteur2D(stod(donnees[3]), stod(donnees[4])), 
                    Vecteur2D(stod(donnees[5]), stod(donnees[6])));
            }
        }
        fichier.close();
    }

    return nullptr;
}