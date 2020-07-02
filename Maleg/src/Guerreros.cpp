#include "Guerreros.h"

Guerreros::Guerreros() : skeleton("imagenes/skeletonmove.png", 5, 1) {


}

Guerreros::Guerreros(float px, float py, float max, float v) : skeleton("imagenes/skeletonmove.png", 5, 1) {

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
	//Dimensiones del sprite
	skeleton.setCenter(1.5, 1);
	skeleton.setSize(3.3, 3.3);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (velocidad.x > 0.01)skeleton.flip(false, false);
	if (velocidad.x < -0.01)skeleton.flip(true, false);
	skeleton.draw();
	skeleton.loop();
	glPopMatrix();

	// HITBOX
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

void Guerreros::Mueve(float t) {

	ObjetoMovil::Mueve(t);
	Movimiento();
}

void Guerreros::Movimiento() {

	if (posicion.x > lim_xd) {
		posicion.x = lim_xd;
		velocidad.x = -0.8f;
		aceleracion.x = -0.2f;
	}
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.x = 0.8f;
		aceleracion.x = 0.2f;
	}
}