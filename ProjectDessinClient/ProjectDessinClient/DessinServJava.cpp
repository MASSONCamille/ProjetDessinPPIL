#include "DessinServJava.h"

int DessinServJava::Dessiner(const Fenetre *f, const Cercle *c) const
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

int DessinServJava::Dessiner(const Fenetre *f, const Croix *c) const
{
	string msg = "croix/"; //"croix/$numfen/$x1/$y1/$x2/$y2"
	msg = msg
		+ to_string(f->getNumFen()) + "/"
		+ to_string((int)c->getVec().getX()) + "/"
		+ to_string((int)c->getVec().getY()) + "/"
		+ to_string((int)(c->getDiagonale().getX() + c->getVec().getX())) + "/"
		+ to_string((int)(c->getDiagonale().getY() + c->getVec().getY()));

	Client::getInstance()->rqtServ(msg);

	return 0;
}

int DessinServJava::Dessiner(const Fenetre *f, const Segment *s) const
{
	string msg = "segment/"; //"segment/$numfen/$x1/$y1/$x2/$y2"
	msg = msg
		+ to_string(f->getNumFen()) + "/"
		+ to_string((int)s->getVec().getX()) + "/"
		+ to_string((int)s->getVec().getY()) + "/"
		+ to_string((int)(s->getPoint().getX() + s->getVec().getX())) + "/"
		+ to_string((int)(s->getPoint().getY() + s->getVec().getY()));

	Client::getInstance()->rqtServ(msg);

	return 0;
}

int DessinServJava::Dessiner(const Fenetre *f, const Polygone *p) const {

	vector<Vecteur2D> lstvect = p->getListPoint();
	lstvect.insert(lstvect.begin(), Vecteur2D(0,0));
	lstvect.insert(lstvect.end(), Vecteur2D(0,0));

	for (int i=1; i <= p->getNbPoint() ; i++) {

		Vecteur2D vo, vp; // les 2 vecteurs du segment vo -> origin | vp -> point
		vo = p->getVec() + lstvect[i-1];
		vp = p->getVec() + lstvect[i] - vo;

		Segment seg = Segment(p->getColor(), vo, vp);

		cout << seg.getVec().getX() << "|" << seg.getVec().getY() << " --> ";
		cout << seg.getPoint().getX() << "|" << seg.getPoint().getY() << endl;

		if(seg.Dessiner(f, this)) return 1; // tracer 
	}

	return 0;
}

int DessinServJava::Dessiner(const Fenetre *f, const Triangle *t) const {
	Segment *s1 = new Segment(t->getColor(), t->getVec(), t->getP2()),
			*s2 = new Segment(t->getColor(), t->getVec(), t->getP3()),
			*s3 = new Segment(t->getColor(), t->getVec() + t->getP2(),
											 t->getVec() + t->getP3());
	
	int res = s1->Dessiner(f, this) +
		s2->Dessiner(f, this) +
		s3->Dessiner(f, this);

	return res;
}


int DessinServJava::Afficher(const Fenetre *f) const
{
	if (f->isAfficher()) return 1; //on ne peut pas dessiner 2X la meme fenetre

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
