#pragma once

#include "FormeGeometriqueBase.h"
#include <string>

using namespace std;

class Charger
{

public:

	virtual FormeGeometriqueBase* charger(string nomFichier, string forme) const = 0;
};
