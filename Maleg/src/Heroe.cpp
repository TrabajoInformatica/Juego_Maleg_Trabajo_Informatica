#include "Heroe.h"

Heroe::Heroe()
{
	vida = 100;
	altura = 3.0f;
	rojo = verde = azul = 255;
	posicion.x = 0.0f;
	posicion.y = 6.0f;
	aceleracion.y = -20.f;
}

Heroe::~Heroe()
{
}

