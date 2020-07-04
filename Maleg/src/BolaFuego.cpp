#include "BolaFuego.h"

BolaFuego::BolaFuego(float px,float py) {
	posicion.x = px;
	posicion.y = py;
	rojo = 255;
	verde = 0;
	azul = 0;
	aceleracion.y = 10.0;
}

BolaFuego::~BolaFuego() {

}

void BolaFuego::Dibuja() {
	//if (estado == Show) {
		glPushMatrix();
		glColor3ub(rojo, verde, azul);
		glTranslatef(posicion.x, posicion.y, 0);
		glColor3f(rojo, verde, azul);
		glutWireSphere(altura, 10, 10);
		glTranslatef(-posicion.x, -posicion.y, 0);
		glPopMatrix();
//	}
}

void BolaFuego::Mueve(float t) {
	ObjetoMovil::Mueve(t);
}

