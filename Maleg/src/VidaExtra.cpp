#include "VidaExtra.h"
#include "glut.h"

VidaExtra::VidaExtra() {
	radio = 0.5f;
	rojo = 255;
	verde = azul = 0;
	velocidad.x = 0;
	velocidad.y = -3.0f;
}
VidaExtra::~VidaExtra() {

}
void VidaExtra::Dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
void VidaExtra::Mueve(float t, float dist) {
	ObjetoMovil::Mueve(t);
	if (posicion.y <= dist)
		velocidad.y = 0.0;

}

