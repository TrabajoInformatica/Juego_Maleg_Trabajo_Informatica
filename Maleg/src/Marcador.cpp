#pragma warning(disable:4996)
#include "ETSIDI.h"
#include "Marcador.h"



Marcador::Marcador(){
const 	char* p = "100%";
	vida = new char[strlen(p) + 1];
	strcpy(vida, p);

}
void Marcador::Dibuja(Personaje *per) {
	// char* p = (char)puntos;
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
Vector2D pos= per->GetPos();
	float ix = pos.x + 15;
	float ij = pos.y + 20;
	ETSIDI::printxy("Vida:", ix-2.5, ij);
	ETSIDI::printxy(vida,ix , ij);
	//ETSIDI::printxy("Hola", 10, 15);
}
