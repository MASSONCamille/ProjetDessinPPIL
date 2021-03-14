#pragma once

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Erreur
{
public:
	const static int LONGUEURMESSAGE = 100;
	char message[1 + LONGUEURMESSAGE];
	Erreur();
	Erreur(const char * messageErreur);

	operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);