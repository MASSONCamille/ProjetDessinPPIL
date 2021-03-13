#pragma once

#include <string>

using namespace std;

class Charger
{

public:

	virtual const char* charger(string nomFichier, string forme) const = 0;
};
