#include "Pajaro.h"

Pajaro::Pajaro(){
	
	verde = 255;
	azul = 0;
	rojo = 0;
	altura = 0.5f;
	velocidad.x = 1.0f;
	lim_xi = posicion.x -10.0f;
	lim_yi = posicion.y + 7.0f;
	lim_xd = posicion.x + 10.0f;
	lim_yd = posicion.y - 7.0f;
}

Pajaro::~Pajaro() {



}
Pajaro::Pajaro(float px, float py) {

	posicion.x = px;
	posicion.y = py;
	verde = 255;
	azul = 0;
	rojo = 0;
	altura = 0.5f;
	velocidad.x = 1.0f;
	lim_xi = posicion.x - 10.0f;
	lim_yi = posicion.y + 7.0f;
	lim_xd = posicion.x + 10.0f;
	lim_yd = posicion.y - 7.0f;

}

/*void Pajaro::Mueve(float t) {

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	Movimiento();
}*/

void Pajaro::Movimiento() {

	if (posicion.x > lim_xd) {
		posicion.x = lim_xd;
		velocidad.x = -1.0f;
		aceleracion.x = -1.0f;
	}
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.x = 1.0f;
		aceleracion.x = 1.0f;
	}

}

