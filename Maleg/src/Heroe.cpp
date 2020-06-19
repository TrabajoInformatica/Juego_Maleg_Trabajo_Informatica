#include <iostream>
#include "Heroe.h"
using namespace std;

Heroe::Heroe() :sprite("imagenes/correr_escudo.png", 4, 3) {
	// Relativo a los atributos
	sprite.setCenter(1,1);
	sprite.setSize(3, 3);
	vida = 100;
	altura = 2.0f;
	rojo = verde = azul = 255;

	// Relativo al movimiento
}
Heroe::~Heroe(){

}

void Heroe::SetAlturaMuerte(float am) {
	alturamuerte = am;
}

void Heroe::SetVida(float v) {
	vida = v;
	//cout << vida << endl;
}

void Heroe::Mueve(float t) {
	ObjetoMovil::Mueve(t);
	sprite.loop();
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

void Heroe::Dibuja() {
	{
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
		glPopMatrix();
	}
}