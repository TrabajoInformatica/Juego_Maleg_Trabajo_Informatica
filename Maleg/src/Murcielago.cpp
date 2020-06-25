#include "Murcielago.h"

Murcielago::Murcielago(): bat("imagenes/bat.png", 3, 1) {

}

Murcielago::Murcielago(float px, float py): bat("imagenes/bat.png", 3, 1) {
	
	posicion.x = px;
	posicion.y = py;
	altura = 0.5;
	velocidad.x = -0.8f;
	velocidad.y = -0.8f;
	aceleracion.x = -0.4f;
	aceleracion.y = -0.4f;
	lim_xd = posicion.x; //+ 3.0f;
	lim_xi = posicion.x - 8.0f;
	lim_ya = posicion.y; //+ 3.0f;
	lim_yb = posicion.y - 4.0f;
}

Murcielago::~Murcielago() {

}

void Murcielago::Dibuja() {
	//Dimensiones del sprite
	bat.setCenter(1.3, 1);
	bat.setSize(2.4, 2.4);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (velocidad.x > 0.01)bat.flip(false, false);
	if (velocidad.x < -0.01)bat.flip(true, false);
	bat.draw();
	bat.loop();
	glPopMatrix();

	// Hitbox
	/*
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutWireSphere(altura, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
	*/
}

void Murcielago::Mueve(float t) {

	ObjetoMovil::Mueve(t);
	Movimiento();
}

void Murcielago::Movimiento() {

	if (posicion.y < lim_yb) {
		posicion.y = lim_yb;
		velocidad.x = -0.8f;
		velocidad.y = 0.8f;
		aceleracion.x = -0.4f;
		aceleracion.y = 0.4f;

	}
	
	else if ((posicion.y > lim_ya ) && (posicion.x < lim_xi)) {

		posicion.y = lim_ya;
		posicion.x = lim_xi;
		velocidad.x = 0.8f;
		velocidad.y = 0;
		aceleracion.x = 0.4f;
		aceleracion.y = 0;

	}
	
	else if (posicion.x > lim_xd) {

		posicion.x = lim_xd;
		velocidad.x = -0.8f;
		velocidad.y = -0.8f;
		aceleracion.x = -0.4f;
		aceleracion.y = -0.4f;
	}
}