#pragma once
#include "Heroe.h"
#include "Enemigo.h"
#include "Plataforma.h"
#include "Moneda.h"
#include "Arma.h"
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
	static bool ColisionEnemigo(Arma a, Enemigo e);
	static bool ColisionSup(Enemigo *e,Plataforma pl);
	static bool ColisionLat(Enemigo* e, Plataforma pl);
};

