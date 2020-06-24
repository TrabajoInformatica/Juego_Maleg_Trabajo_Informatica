#include "VidaExtra.h"
#include <iostream>
#include "glut.h"
using namespace std;

VidaExtra::VidaExtra() {
	rojo = 220;
	verde = 0;
	azul = 0;
	velocidad.x = 0;
	velocidad.y = -3.0;
	radio = 0.5f;
}
VidaExtra::~VidaExtra() {

}

void VidaExtra::Dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}


bool VidaExtra::ColisionVida(Heroe* p,VidaExtra v) {
	/*if (Interaccion::ColisionVidaExtra(p, v)) {
		cout << "colision vida" << endl;
		return true;
	}
	else
		return false;*/
	return false;
}
void VidaExtra::Mueve(float t, float dist) {

	ObjetoMovil::Mueve(t);
	if (posicion.y <= dist)
		velocidad.y = 0.0f;
}