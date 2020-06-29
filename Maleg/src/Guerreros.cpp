#include "Guerreros.h"

Guerreros::Guerreros() {


}

Guerreros::Guerreros(float px, float py, float max, float v) {

	posicion.x = px;
	posicion.y = py;
	altura = 1.0f;
	velocidad.x = v;
	//aceleracion.x = -0.5f;
	lim_xd = posicion.x + max ;
	lim_xi = posicion.x - max;
	
}

Guerreros::~Guerreros() {


}

void Guerreros::Dibuja() {

	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutWireSphere(altura, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Guerreros::Mueve(float t) {

	ObjetoMovil::Mueve(t);
	Movimiento();
}

void Guerreros::Movimiento() {

	if (posicion.x > lim_xd) {
		posicion.x = lim_xd;
		velocidad.x = -1.5f;
		aceleracion.x = -0.5f;
	}
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.x = 1.5f;
		aceleracion.x = 0.5f;
	}
}