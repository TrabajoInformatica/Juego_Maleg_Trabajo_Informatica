#include "Guerreros.h"

Guerreros::Guerreros() {


}

Guerreros::Guerreros(float px, float py) {

	posicion.x = px;
	posicion.y = py;
	altura = 2.0f;
	velocidad.x = -3.0f;
	velocidad.y = -3.0f;
	aceleracion.x = -0.5f;
	aceleracion.y = -0.5f;
	
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

}