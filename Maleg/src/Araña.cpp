#include "Araña.h"

Araña::Araña() {

}

Araña::Araña(float px, float py) {
	
	posicion.x = px;
	posicion.y = py;
	aceleracion.x = 1.0;
	verde = 0;
	azul = 0;
	rojo = 255;
	altura = 0.7f;
	velocidad.x = 1.0f;
	lim_xi = posicion.x - 10.0f;
	lim_ya = posicion.y + 2.0f;
	lim_xd = posicion.x + 10.0f;
	lim_yb = posicion.y - 7.0f;
}

Araña::~Araña() {

}

void Araña::Mueve(float t) {

	ObjetoMovil::Mueve(t);
	Movimiento();
}

void Araña::Movimiento() {

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
		velocidad.y = 2.5f;
		aceleracion.y = 2.0f;
	}
	else if (posicion.y > lim_ya) {
		posicion.y = lim_ya;
		velocidad.x = -2.5f;
		aceleracion.x = -2.0f;
	}
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.y = -2.5f;
		aceleracion.y = -2.0f;
	}
	else if (posicion.y < lim_yb) {
		posicion.y = lim_yb;
		velocidad.x = 2.5f;
		aceleracion.x = 2.0f;
	}

}

void Araña::Dibuja() {
	
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutWireSphere(altura, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}