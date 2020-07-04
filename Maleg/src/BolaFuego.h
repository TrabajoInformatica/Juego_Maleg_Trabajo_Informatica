#pragma once
#include "Enemigo.h"
class BolaFuego:public Enemigo {
protected:

public:
	BolaFuego(float px, float py,float a);
	virtual ~BolaFuego();
	void Mueve(float t);
	void Dibuja();
};