#include "Personaje.h"

Personaje::Personaje(){

}

Personaje::~Personaje(){

}

void Personaje::SetAltura(float a){
	altura = a;
}

float Personaje::GetAltura(){
	return altura;
}

void Personaje::DestruirContenido(){

}

void Personaje::ShowHitbox(bool e) {
	if (e == true)
		estado = Show;
	else
		estado = Hide;
}