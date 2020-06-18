#pragma once
#include "Heroe.h"
#include "Enemigo.h"
#include "Plataforma.h"
#include "Moneda.h"
class Interaccion
{
private:

public:
	Interaccion();
	virtual ~Interaccion();

	static bool ColisionSup(Heroe* pers, Plataforma pl);
	static bool ColisionLat(Heroe* pers, Plataforma pl);
	static bool ColisionInf(Heroe* pers, Plataforma pl);
	static bool ColisionMoneda(Heroe* pers, Moneda m);
	static bool ColisionEnemigo(Heroe* pers, Enemigo e);
};

