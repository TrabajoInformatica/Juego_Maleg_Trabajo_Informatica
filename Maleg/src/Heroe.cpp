#include "Heroe.h"

Heroe::Heroe() :sprite("imagenes/jugador.png", 5, 2) {
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

bool Heroe::Muerte() {
	if (alturamuerte >= posicion.y) {
		return true;
	}
	else if (vida == 0) {
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

void Heroe::Mueve(float t) {
	ObjetoMovil::Mueve(t);
	sprite.loop();
}

