#include <iostream>
#include "Heroe.h"
using namespace std;

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

void Heroe::SetVida(float v) {
	vida = v;
	cout << vida << endl;
	


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

