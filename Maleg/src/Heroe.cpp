#include "Heroe.h"

Heroe::Heroe(){
	// Relativo a los atributos
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
	if (alturamuerte <= posicion.y) {
		return true;
	}
	else if (vida == 0) {
		return true;
	}
	else
		return false;
	
}

