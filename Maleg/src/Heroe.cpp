#include "Heroe.h"

Heroe::Heroe()
{
	//Relativo a propiedades
	vida = 100;
	altura = 3.0f;
	rojo = verde = azul = 255;
	//Relativo al movimiento
	posicion.x = 0.0f;
	posicion.y = 3.0f;
	aceleracion.y = -9.8f;
}

Heroe::~Heroe()
{
}

