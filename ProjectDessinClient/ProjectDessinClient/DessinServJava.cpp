#include "DessinServJava.h"

int DessinServJava::Dessiner(const Fenetre * f, const Cercle * c) const
{
	string msg = "rond/"; //"rond/$numfen/$x/$y/$rayon"
	msg = msg
		+ to_string(f->getNumFen()) + "/"
		+ to_string((int) c->getVec().getX()) + "/"
		+ to_string((int) c->getVec().getY()) + "/"
		+ to_string((int) c->getRayon());

	Client::getInstance()->rqtServ(msg);

	return 0;
}

int DessinServJava::Dessiner(const Fenetre * f, const Croix * c) const
{
	string msg = "croix/"; //"croix/$numfen/$x1/$y1/$x2/$y2"
	msg = msg
		+ to_string(f->getNumFen()) + "/"
		+ to_string((int)c->getVec().getX()) + "/"
		+ to_string((int)c->getVec().getY()) + "/"
		+ to_string((int)c->getDiagonale().getX()) + "/"
		+ to_string((int)c->getDiagonale().getY());

	Client::getInstance()->rqtServ(msg);

	return 0;
}

int DessinServJava::Dessiner(const Fenetre * f) const
{
	if (f->isDessiner()) return 1; //on ne peut pas dessiner 2X la meme fenetre

	string msg = "ouvrirfenetre/"; //"ouvrirfenetre/$numfen/$titrefenetre/$x/$y/$width/$height"
	msg = msg
		+ to_string(f->getNumFen()) + "/"
		+ f->getNomFen() + "/"
		+ to_string(f->getX()) + "/" + to_string(f->getY()) + "/"
		+ to_string(f->getWidth()) + "/" + to_string(f->getHeight());

	Client::getInstance()->rqtServ(msg);

	return 0;
}

int DessinServJava::Effacer(const Fenetre *f) const
{
	string msg = "effacer/"; //"effacer/$numfen"
	msg = msg + to_string(f->getNumFen());

	Client::getInstance()->rqtServ(msg);

	return 0;
}

/**
-Ouvrir fenetre: "ouvrirfenetre/$numfen/$titrefenetre/$x/$y/$width/$height"
-Effacer fenetre: "effacer/$numfen"
-Dessin rond: "rond/$numfen/$x/$y/$rayon"
-Dessin croix: "croix/$numfen/$x1/$y1/$x2/$y2"
*/
