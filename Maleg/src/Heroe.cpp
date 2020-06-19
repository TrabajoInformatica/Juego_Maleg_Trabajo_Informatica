#include <iostream>
#include "Heroe.h"
using namespace std;

Heroe::Heroe() :sprite("imagenes/spartanRUN.png", 4, 2) , salto("imagenes/spartanJUMPup.png", 4, 2){
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
	sprite.setCenter(1.2, 1.2);
	sprite.setSize(3, 3);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	sprite.loop();
	glPopMatrix();

}
void Heroe::AnimationJump(){
	//Dimensiones del sprite
	//salto.setCenter(1.0, 1.0);
	//salto.setSize(3, 3);
	salto.setCenter(1.2, 1.2);
	salto.setSize(3, 3);
//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)salto.flip(false, false);
	if (velocidad.x < -0.01)salto.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		salto.setState(0);
	else if (salto.getState() == 0)
		salto.setState(1, false);
	salto.draw();
	salto.loop();
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

