#include "Enemigo.h"

Enemigo::Enemigo()
{
	verde = 255;
	rojo = 0;
	azul = 100;
}

Enemigo::~Enemigo()
{

}

Enemigo::Enemigo(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

