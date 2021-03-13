#include "Client.h"

#include "DessinServJava.h"


int main() {
	Cercle *cercle1 = new Cercle(FormeGeometriqueBase::BLACK, Vecteur2D(100, 100), 50);
	Croix *croix1 = new Croix(FormeGeometriqueBase::BLACK, Vecteur2D(50, 50), Vecteur2D(100, 100));
	Segment *segment1 = new Segment(FormeGeometriqueBase::BLACK, Vecteur2D(110, 110), Vecteur2D(100, 100));

	Vecteur2D v1, v2, v3;
	v1 = Vecteur2D(0,1);
	v2 = Vecteur2D(1,1);
	v3 = Vecteur2D(1,0);
	vector<Vecteur2D> lstvec = { v1, v2, v3 };
	Polygone *polygone1 = new Polygone(FormeGeometriqueBase::BLACK, Vecteur2D(1, 1), lstvec.size()+1);
	polygone1->setListPoint(lstvec);

	VisitorDessin * ServJava;
	ServJava = new DessinServJava();
	
	Fenetre * f1 = new Fenetre();

	polygone1->Dessiner(f1, ServJava);
	
	if (f1->Afficher(ServJava))
		cout << "fenetre deja dessiner" << endl << endl;

	//if (f1->Afficher(ServJava))
	//	cout << "fenetre deja dessiner" << endl << endl;

	if (cercle1->Dessiner(f1, ServJava))
		cout << "erreur cercle" << endl << endl;

	//if (segment1->Dessiner(f1, ServJava))
	//	cout << "erreur segment" << endl << endl;

	//if (f1->Effacer(ServJava))
	//	cout << "erreur effacer" << endl << endl;

	//if (croix1->Dessiner(f1, ServJava))
	//	cout << "erreur cercle" << endl << endl;

	int x;
	cin >> x;


}