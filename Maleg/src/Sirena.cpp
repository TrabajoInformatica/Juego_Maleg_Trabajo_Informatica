
#include "Sirena.h"



Sirena::Sirena() {

	verde = 255;
	rojo = 0;
	azul = 100;
	altura = 1.0f;
	salto_max = 20.0f;
	salto_min = 3.0f;
	velocidad.y = 5.0;
}

Sirena::~Sirena() {

}


Sirena::Sirena(float px, float py) {

	posicion.x = px;
	posicion.y = py;
	
}

void Sirena::Mueve(float t) {
	
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	Salto();
}

void Sirena::Salto() {
	
	if (posicion.y < salto_min) {
		posicion.y = salto_min;
		velocidad.y = 10.0f;
		aceleracion.y = 2.0f;
	}
	else if (posicion.y > salto_max) {
		posicion.y = salto_max;
		velocidad.y = -7.0f;
		aceleracion.y = -2.0f;
	}
}