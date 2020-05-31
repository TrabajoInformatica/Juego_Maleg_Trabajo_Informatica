#include "Heroe.h"

Heroe::Heroe()
{
	// Relativo a los atributos
	vida = 100;
	altura = 3.0f;
	rojo = verde = azul = 255;

	// Relativo al movimiento
	posicion.x = 0.0f;
	posicion.y = 3.0f;

	velocidad.x = 0.0f;
	velocidad.y = 0.0f;
}

Heroe::~Heroe()
{
}

