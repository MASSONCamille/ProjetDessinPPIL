#include "DessinServJava.h"


int main() {
	Cercle *cercle1 = new Cercle(FormeGeometriqueBase::BLACK, Vecteur2D(100, 100), 50);
	Croix *croix1 = new Croix(FormeGeometriqueBase::BLUE, Vecteur2D(100, 100), Vecteur2D(100, 100));
	Segment *segment1 = new Segment(FormeGeometriqueBase::RED, Vecteur2D(100, 100), Vecteur2D(100, -100));
	Triangle *triangle1 = new Triangle(FormeGeometriqueBase::GREEN, Vecteur2D(110, 110), Vecteur2D(100, 0), Vecteur2D(0, 100));


	Vecteur2D v1, v2, v3;
	v1 = Vecteur2D(0,100);
	v2 = Vecteur2D(100,100);
	v3 = Vecteur2D(100,0);
	vector<Vecteur2D> lstvec = { v1, v2, v3 };
	Polygone *polygone1 = new Polygone(FormeGeometriqueBase::CYAN, Vecteur2D(100, 100), lstvec.size()+1);
	polygone1->setListPoint(lstvec);

	VisitorDessin * ServJava;
	ServJava = new DessinServJava();
	
	Fenetre *f1 = new Fenetre();
	

	//------------------------------------------------//
	//--- TEST CONSOLE ---//

	cout << *f1 << endl;
	cout << *croix1 << endl;
	cout << *cercle1 << endl;
	cout << *segment1 << endl;
	cout << *triangle1 << endl;
	cout << *polygone1 << endl;
	cout << endl;

	cout << *polygone1 << endl;
	polygone1->Traslation(Vecteur2D(100, 100));
	cout << *polygone1 << endl;
	polygone1->Rotation(Vecteur2D(200, 200), 90);
	cout << *polygone1 << endl;


	cout << endl << endl;
	//------------------------------------------------//
	//--- TEST SERVEUR ---//

	//// Fenetre
	//if (f1->Afficher(ServJava))
	//	cout << "fenetre deja dessiner" << endl << endl;
	//// Test anti-double
	//if (f1->Afficher(ServJava))
	//	cout << "fenetre deja dessiner" << endl << endl;

	//// croix
	//if (croix1->Dessiner(f1, ServJava))
	//	cout << "erreur croix" << endl << endl;
	//int x;
	//cin >> x; //tempo

	//// effacer
	//if (f1->Effacer(ServJava))
	//	cout << "erreur effacer" << endl << endl;
	//cin >> x; //tempo

	//// cercle
	//if (cercle1->Dessiner(f1, ServJava))
	//	cout << "erreur cercle" << endl << endl;
	//cin >> x; //tempo

	//// segment
	//if (segment1->Dessiner(f1, ServJava))
	//	cout << "erreur segment" << endl << endl;
	//cin >> x; //tempo

	//// triangle
	//if (triangle1->Dessiner(f1, ServJava))
	//	cout << "erreur triangle" << endl << endl;
	//cin >> x; //tempo

	//// polygone
	//if (polygone1->Dessiner(f1, ServJava))
	//	cout << "erreur polygone" << endl << endl;
	//cin >> x; //tempo

	//// fermer client
	//f1->Detruire(ServJava);

	//Client::getInstance()->fermerClient();
}