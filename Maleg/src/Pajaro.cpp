#include "Pajaro.h"

Pajaro::Pajaro(){
	verde = 255;
	azul = 0;
	rojo = 0;
	altura = 0.5f;
}

Pajaro::Pajaro(float px, float py) {

	verde = 255;
	azul = 0;
	rojo = 0;
	altura = 0.5f;
	posicion.x = px;
	posicion.y = py;
	velocidad.x = 1.0;
	salto_max = posicion.x+5.0;
	salto_min = posicion.x-3.0;


}

Pajaro::~Pajaro() {


}

void Pajaro::Mueve(float t) {
	ObjetoMovil::Mueve(t);

		if (posicion.x < salto_min) {

			posicion.x = salto_min;
			velocidad.x = 10.0f;
			aceleracion.x = 1.5f;
		}

		else if (posicion.x > salto_max) {

			posicion.x = salto_max;
			velocidad.x = -2.0f;
			aceleracion.x = -0.5f;
		}
}