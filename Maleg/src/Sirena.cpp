
#include "Sirena.h"
#include "glut.h"



Sirena::Sirena() {

	verde = 255;
	rojo = 0;
	azul = 100;
	altura = 1.0f;
	salto_max = 15.0f;
	salto_min = 3.0f;
	velocidad.y = 2.0;
}
Sirena::Sirena(float x, float y) {
	posicion.x = x;
	posicion.y = y;
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

void Sirena::Mueve(float t) {
	ObjetoMovil::Mueve(t);
	Salto();
}

void Sirena::Salto() {

	if (posicion.y < salto_min) {

		posicion.y = salto_min;
		velocidad.y = 10.0f;
		aceleracion.y = 1.5f;
	}

	else if (posicion.y > salto_max) {

		posicion.y = salto_max;
		velocidad.y = -2.0f;
		aceleracion.y = -0.5f;
	}

}

