#include "Sirena.h"

Sirena::Sirena() {

	verde = 255;
	rojo = 0;
	azul = 100;
	altura = 1.0f;
	salto_max = 8.0f;
	salto_min = 2.0f;
}

Sirena::~Sirena() {

}


Sirena::Sirena(float px, float py) {

	posicion = (px,py);

}

void Sirena::Salto(Sirena &s) {

	if (s.posicion.y < salto_min) {

		s.posicion.y = salto_min;
		s.velocidad.y = 2.0f;
		s.aceleracion.y = 0.5f;
	}

	else if (s.posicion.y > salto_max) {

		s.posicion.y = salto_max;
		s.velocidad.y = -2.0f;
		s.aceleracion.y = 0.5f;
	}

}
