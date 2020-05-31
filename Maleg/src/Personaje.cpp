#include "Personaje.h"

Personaje::Personaje(){
	altura = 3.0f;
	rojo = verde = azul = 255;
}

Personaje::~Personaje(){

}

void Personaje::SetAltura(float a){
	altura = a;
}

float Personaje::GetAltura(){
	return altura;
}



void Personaje::Dibuja(){

	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0); //dibujar los objetos donde queramos
	glutSolidCube(altura);
	glTranslatef(-posicion.x, -posicion.y, 0);
	
}

void Personaje::DestruirContenido(){

}

