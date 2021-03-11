#pragma once

#include <string>
#include <iostream>
#include <stdio.h>

class VisitorDessin;

using namespace std;

class Fenetre
{
private:
	static int nbFen;

	int _numFen;
	string _nomFen;
	int _x, _y;
	int _width, _height;
	bool _dessiner;

public:
	inline Fenetre() {
		_numFen = nbFen;
		nbFen++;

		_dessiner = false;

		_nomFen = "defaultName";
		_x = _y = 0;
		_width = _height = 1000;
	}

	virtual ~Fenetre() {}; // TODO le destructeur doit appeler Fermer() (TODO)

	inline int getNBFen() const {
		return nbFen;
	}

	inline int getNumFen() const{
		return _numFen;
	}
	inline string getNomFen() const {
		return _nomFen;
	}
	inline int getX() const {
		return _x;
	}
	inline int getY() const {
		return _y;
	}
	inline int getWidth() const {
		return _width;
	}
	inline int getHeight() const {
		return _height;
	}
	inline bool isDessiner() const {
		return _dessiner;
	}


	inline void setNomFen(const string name) {
		_nomFen = name;
	}
	inline void setX(const int x) {
		_x = x;
	}
	inline void setY(const int y) {
		_y = y;
	}
	inline void setWidth(const int w) {
		_width = w;
	}
	inline int setHeight(const int h) {
		_height = h;
	}
	
	int Dessiner(VisitorDessin *);
	int Effacer(VisitorDessin *);
};

