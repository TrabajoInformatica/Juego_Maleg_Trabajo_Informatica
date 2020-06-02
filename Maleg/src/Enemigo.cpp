#include "Enemigo.h"

Enemigo::Enemigo()
{
	verde = 255;
	rojo = 100;
	azul = 100;
}

Enemigo::~Enemigo()
{

}

void Enemigo::Dibuja() {

	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutSolidSphere(altura, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
