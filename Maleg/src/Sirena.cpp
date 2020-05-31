#include "Sirena.h"

Sirena::Sirena() {

	verde = 255;
	rojo = 0;
	azul = 100;
	altura = 2.0f;
	salto_max = 8.0f;
	salto_min = 2.0f;
}

Sirena::~Sirena() {

}

void Sirena::Salto(Sirena &s) {

	if (s.posicion.y < salto_min) {

		s.posicion.y = salto_min;
		s.SetVel(0, 2.0f);
		s.SetAce(0, 0.5f);
	}

	else if (s.posicion.y > salto_max) {

		s.posicion.y = salto_max;
		s.SetVel(0, -2.0f);
		s.SetAce(0, -0.5f);
	}

}
