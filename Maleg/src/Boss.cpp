#include "Boss.h"
#include "ObjetoMovil.h"

Boss::Boss() {

}

Boss::Boss(float x, float y) {

	posicion.x = x;
	posicion.y = y;
	altura = 4.0f;
	velocidad = 0;
	aceleracion = 0;
}

Boss::~Boss() {

}

void Boss::Mueve(float t) {

	ObjetoMovil::Mueve(t);
}

void Boss::Dibuja() {

	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutWireSphere(altura, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

bool Boss::AgregarB(Boss* b) {

	if (num < MAX_BOSS) {
		lista[num] = b;

		num++;

	}
	else return false;
}