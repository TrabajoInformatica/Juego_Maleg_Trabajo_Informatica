#include "Ara�a.h"

Ara�a::Ara�a() {

}

Ara�a::Ara�a(float px, float py) {
	
	posicion.x = px;
	posicion.y = py;
	aceleracion.x = 1.0;
	verde = 0;
	azul = 0;
	rojo = 255;
	altura = 0.4f;
	velocidad.x = 1.0f;
	lim_xi = posicion.x - 3.0f;
	lim_ya = posicion.y + 0.75f;
	lim_xd = posicion.x + 3.0f;
	lim_yb = posicion.y - 0.75f;
}

Ara�a::~Ara�a() {

}

void Ara�a::Mueve(float t) {

	ObjetoMovil::Mueve(t);
	Movimiento();
}

void Ara�a::Movimiento() {

	/*if (posicion.x > lim_xd ) {
		posicion.x = lim_xd;
		velocidad.x = -2.5f;
		aceleracion.x = -2.0f;
	}
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.x = 2.5f;
		aceleracion.x = 2.0f;
	}*/
	if (posicion.x > lim_xd) {
		posicion.x = lim_xd;
		velocidad.y = 0.5f;
		aceleracion.y = 0.05f;

		if (posicion.y > lim_ya) {
			posicion.y = lim_ya;
			velocidad.x = -0.5f;
			aceleracion.x = -0.05f;
			velocidad.y = 0;
			aceleracion.y = 0;

		}
	}
	/*else if (posicion.y > lim_ya) {
		posicion.y = lim_ya;
		velocidad.x = -2.5f;
		aceleracion.x = -2.0f;
	}*/
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.y = -0.5f;
		aceleracion.y = -0.05f;
		velocidad.x = 0;
		aceleracion.x = 0;
		}

	else if (posicion.y < lim_yb) {
		posicion.y = lim_yb;
		velocidad.x = 0.5f;
		aceleracion.x = 0.05f;
		velocidad.y = 0;
		aceleracion.y = 0;
		}
	
	/*else if (posicion.y < lim_yb) {
		posicion.y = lim_yb;
		velocidad.x = 2.5f;
		aceleracion.x = 2.0f;
	}*/

}

void Ara�a::Dibuja() {
	
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutWireSphere(altura, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}