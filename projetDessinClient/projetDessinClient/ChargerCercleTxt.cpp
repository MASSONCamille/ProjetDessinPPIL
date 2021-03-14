#include "ChargerCercleTxt.h"
#include "Cercle.h"
#include <regex>
#include <fstream>

ChargerCercleTxt::ChargerCercleTxt(ChargerCOR* suivant) : ChargerCOR(suivant) {}

FormeGeometriqueBase* ChargerCercleTxt::charger1(string nomFichier, string forme) const
{
    if (regex_match(nomFichier, regex("(\\w+).txt$")) && forme == "cercle") { //Test fichier de type txt et forme rechercher cercle
        string ligne;
        ifstream fichier;
        fichier.open("../Sauvegardes/" + nomFichier); //Ouverture du fichier du répertoire Sauvegardes
        if (fichier.good()) { //Vérifie que le fichier est trouvé et accessible
            if (getline(fichier, ligne)) { //Vérifie qu'il y a une ligne d'écrite
                size_t pos = 0;
                int i = 0;
                string delimiter = "/";
                string donnees[4];
                while ((pos = ligne.find(delimiter)) != string::npos && i < 4) { //Boucle qui récupère les informations entre chaque "/"
                    donnees[i] = ligne.substr(0, pos);
                    ligne.erase(0, pos + delimiter.length());
                    i++;
                }
                return new Cercle((FormeGeometriqueBase::Couleurs)stoi(donnees[0]), Vecteur2D(stod(donnees[1]), stod(donnees[2])), stoi(donnees[3])); //Construit le cercle à partir des données
            }
        }
        fichier.close();
    }

    return nullptr;
}