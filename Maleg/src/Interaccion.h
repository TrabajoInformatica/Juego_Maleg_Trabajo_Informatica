#pragma once
#include "Personaje.h"
#include "Enemigo.h"
#include "Plataforma.h"
#include "Moneda.h"
class Interaccion
{
private:

public:
	Interaccion();
	virtual ~Interaccion();

	static bool ColisionSup(Personaje* pers, Plataforma pl);
	static bool ColisionLat(Personaje* pers, Plataforma pl);
	static bool ColisionInf(Personaje* pers, Plataforma pl);
	static bool ColisionMoneda(Personaje* pers, Moneda m);
	static bool ColisionEnemigo(Personaje* pers, Enemigo e);
};

