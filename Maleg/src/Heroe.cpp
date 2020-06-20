#include <iostream>
#include "Heroe.h"
using namespace std;

Heroe::Heroe() :run("imagenes/spartanRUN.png", 4, 2) , 
				jumpUP("imagenes/spartanJUMPup.png", 4, 2),
				jumpDOWN("imagenes/spartanJUMPdown.png", 4, 3) {
	// Relativo a los atributos
	vida = 100;
	altura = 2.0f;
	rojo = verde = azul = 255;
}
Heroe::~Heroe(){

}
void Heroe::Mueve(float t) {
	ObjetoMovil::Mueve(t);
}

void Heroe::Dibuja() {
	//AnimationJump();
	//AnimationMove();
}

// ANIMACIONES
void Heroe::AnimationRun() {
	//Dimensiones del sprite
	run.setCenter(1.8, 1);
	run.setSize(3, 3);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)run.flip(false, false);
	if (velocidad.x < -0.01)run.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		run.setState(0);
	else if (run.getState() == 0)
		run.setState(1, false);
	run.draw();
	run.loop();
	glPopMatrix();

}
void Heroe::AnimationJumpUp(){
//Dimensiones del sprite
	jumpUP.setCenter(1.8, 1);
	jumpUP.setSize(3, 3);
//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)jumpUP.flip(false, false);
	if (velocidad.x < -0.01)jumpUP.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		jumpUP.setState(0);
	else if (jumpUP.getState() == 0)
		jumpUP.setState(1, false);
	jumpUP.draw();
	jumpUP.loop();
	glPopMatrix();
}

void Heroe::AnimationJumpDown() {
//Dimensiones del sprite
	jumpDOWN.setCenter(1.8, 1);
	jumpDOWN.setSize(3, 3);
//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)jumpDOWN.flip(false, false);
	if (velocidad.x < -0.01)jumpDOWN.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		jumpDOWN.setState(0);
	else if (jumpDOWN.getState() == 0)
		jumpDOWN.setState(1, false);
	jumpDOWN.draw();
	jumpDOWN.loop();
	glPopMatrix();
}

void Heroe::SetAlturaMuerte(float am) {
	alturamuerte = am;
}
void Heroe::SetVida(float v) {
	vida = v;
	//cout << vida << endl;
}
bool Heroe::Muerte() {
	
	if (alturamuerte >= posicion.y) {
		cout << "te has caido" << endl;
		return true;
	}
	 if (vida==0) {
		cout << "muerto por colision" << endl;
	
		return true;
	}
	else
		return false;
	
}

