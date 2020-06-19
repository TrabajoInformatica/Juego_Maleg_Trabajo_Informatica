#include "Sirena.h"

Sirena::Sirena() {

	verde = 255;
	rojo = 0;
	azul = 100;
	altura = 1.0f;
	salto_max = 15.0f;
	salto_min = 3.0f;
	velocidad.y = 2.0;
}

Sirena::~Sirena() {

}


Sirena::Sirena(float px, float py) {

	posicion = (px,py);

}

void Sirena::Salto() {

	if (posicion.y < salto_min) {

		posicion.y = salto_min;
		velocidad.y = 5.0f;
		aceleracion.y = 0.5f;
	}


	else if (posicion.y > salto_max) {

		posicion.y = salto_max;
		velocidad.y = -5.0f;
		aceleracion.y = 0.5f;
	}

}
