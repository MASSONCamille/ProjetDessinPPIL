#include "ChargerPolygoneTxt.h"
#include "Polygone.h"
#include <regex>
#include <fstream>

ChargerPolygoneTxt::ChargerPolygoneTxt(ChargerCOR* suivant) : ChargerCOR(suivant) {}

FormeGeometriqueBase* ChargerPolygoneTxt::charger1(string nomFichier, string forme) const
{
    if (regex_match(nomFichier, regex("(\\w+).txt$")) && forme == "polygone") {
        string ligne;
        ifstream fichier;
        fichier.open("../Sauvegardes/" + nomFichier);
        if (fichier.good()) {
            if (getline(fichier, ligne)) {
                size_t pos = 0;
                int i = 0;
                string delimiter = "/";
                string donnees[4];
                while ((pos = ligne.find(delimiter)) != string::npos && i < 4) {
                    donnees[i] = ligne.substr(0, pos);
                    ligne.erase(0, pos + delimiter.length());
                    i++;
                }
                int nbp = stoi(donnees[3]);
                Polygone* polygone1 = new Polygone((FormeGeometriqueBase::Couleurs)stoi(donnees[0]), Vecteur2D(stod(donnees[1]), stod(donnees[2])), nbp+1);

                i = 0;
                double x, y;
                vector<Vecteur2D> lstvec;
                while ((pos = ligne.find(delimiter)) != string::npos && i < nbp*2) {
                    if (i % 2 == 0)
                        x = stod(ligne.substr(0, pos));
                    else {
                        y = stod(ligne.substr(0, pos));
                        lstvec.push_back(Vecteur2D(x, y));
                    }
                    ligne.erase(0, pos + delimiter.length());
                    i++;
                }
                polygone1->setListPoint(lstvec);

                return polygone1;
            }
        }
        fichier.close();
    }

    return nullptr;
}