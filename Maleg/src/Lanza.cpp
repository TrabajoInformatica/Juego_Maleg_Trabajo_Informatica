#include "Lanza.h"
#include "glut.h"
Lanza::Lanza(float x,float y) {
	posicion.x = x;
	posicion.y = y;
	rojo = 255;
	verde = 45;
	azul = 100;
	lado = 0.5;
}

Lanza::~Lanza() {

}

void Lanza::Dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCube(lado);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Lanza::Mueve(float t) {
	ObjetoMovil::Mueve(t);
}