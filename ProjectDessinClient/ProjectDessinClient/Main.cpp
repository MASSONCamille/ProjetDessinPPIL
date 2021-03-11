#include "Vecteur2D.h"
#include "FormeGeometriqueBase.h"
#include "FormeGeometriqueSimple.h"
#include "Cercle.h"
#include "Croix.h"
#include "Segment.h"

#include "Fenetre.h"
#include "Client.h"

#include "VisitorDessin.h"
#include "DessinServJava.h"

int main() {
	FormeGeometriqueBase * cercle1, * croix1, * segment1;
	cercle1 = new Cercle(FormeGeometriqueBase::BLACK, Vecteur2D(100, 100), 50);
	croix1 = new Croix(FormeGeometriqueBase::BLACK, Vecteur2D(50, 50), Vecteur2D(100, 100));
	segment1 = new Croix(FormeGeometriqueBase::BLACK, Vecteur2D(110, 110), Vecteur2D(100, 100));

	VisitorDessin * ServJava;
	ServJava = new DessinServJava();
	
	Fenetre * f1 = new Fenetre();
	
	if (f1->Afficher(ServJava))
		cout << "fenetre deja dessiner" << endl << endl;

	if (f1->Afficher(ServJava))
		cout << "fenetre deja dessiner" << endl << endl;

	if (cercle1->Dessiner(f1, ServJava))
		cout << "erreur cercle" << endl << endl;

	if (segment1->Dessiner(f1, ServJava))
		cout << "erreur segment" << endl << endl;

	if (f1->Effacer(ServJava))
		cout << "erreur effacer" << endl << endl;

	if (croix1->Dessiner(f1, ServJava))
		cout << "erreur cercle" << endl << endl;

	int x;
	cin >> x;
		// test client
}