#include <iostream>
#include "Heroe.h"
using namespace std;

Heroe::Heroe() : run("imagenes/spartanRUN.png", 4, 3) , 
				 jumpUP("imagenes/spartanJUMPup.png", 4, 2) ,
				 jumpDOWN("imagenes/spartanJUMPdown.png", 4, 3) {
	// Relativo a los atributos
	altura = 2.0f;
	rojo  = azul = 0;
	verde = 255;
}
Heroe::~Heroe(){

}
void Heroe::Mueve(float t) {
	ObjetoMovil::Mueve(t);
}

void Heroe::Dibuja() {
//Dimensiones del sprite
	run.setCenter(1.8, 1.1);
	run.setSize(3, 3);

	jumpUP.setCenter(1.8, 1);
	jumpUP.setSize(3, 3);

	jumpDOWN.setCenter(1.8, 1);
	jumpDOWN.setSize(3, 3);

//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);

	//tratamiento AnimationRUN
	if (velocidad.x > 0.01)run.flip(false, false);
	if (velocidad.x < -0.01)run.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		run.setState(0);
	else if (run.getState() == 0)
		run.setState(1, false);
	//tratamiento AnimationJUMPup
	if (velocidad.x > 0.01)jumpUP.flip(false, false);
	if (velocidad.x < -0.01)jumpUP.flip(true, false);

	//tratamiento AnimationJUMPdown
	if (velocidad.x > 0.01)jumpDOWN.flip(false, false);
	if (velocidad.x < -0.01)jumpDOWN.flip(true, false);

	// OPERANDI DIBUJO
	if (velocidad.y == 0) {
		run.draw();
		run.loop();
	}
	else if (velocidad.y > 0.01f) {
		jumpUP.draw();
		jumpUP.loop();
	}
	else if (velocidad.y < -0.01f) {
		jumpDOWN.draw();
		jumpDOWN.loop();
	}
	glPopMatrix();

	if (estado == Show) {
		//////////Dibuja el Hitbox de pajaro
		glPushMatrix();
		glColor3ub(rojo, verde, azul);
		glTranslatef(posicion.x, posicion.y, 0);
		glColor3f(rojo, verde, azul);
		glutWireCube(altura);
		glTranslatef(-posicion.x, -posicion.y, 0);
		glPopMatrix();
	}
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
		return true;
	}
	 if (vida==0) {
		 cout << vida << endl;
		return true;
	}
	else
		return false;
	
}

int Heroe::GetVida() {
	return vida;
}

void Heroe::ShowHitbox(bool e) {
	if (e == true)
		estado = Show;
	else
		estado = Hide;
}
