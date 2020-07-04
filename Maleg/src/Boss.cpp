#include "Boss.h"
#include "ObjetoMovil.h"

Boss::Boss():boss("imagenes/minotauro.png", 9, 5) {

}

Boss::Boss(float x, float y) : boss("imagenes/minotauro.png", 9, 5) {

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
	//Dimensiones del sprite
	boss.setCenter(5, 5);
	boss.setSize(10, 10);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	//if (velocidad.x > 0.01)boss.flip(false, false);
	//if (velocidad.x < -0.01)boss.flip(true, false);
	boss.flip(true, false);
	boss.draw();
	boss.loop();
	glPopMatrix();

	
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