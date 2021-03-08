#include "Vecteur2D.h"
#include "FormeGeometriqueBase.h"
#include "FormeGeometriqueSimple.h"
#include "Cercle.h"
#include "Client.h"

int main() {
	Cercle c1(FormeGeometriqueBase::BLACK, Vecteur2D(1, 2), 5);

	Client::getInstance()->rqtServ("TEST");
}