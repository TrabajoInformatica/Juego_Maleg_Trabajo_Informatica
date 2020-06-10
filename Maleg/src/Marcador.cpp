#pragma warning(disable:4996)
#include "ETSIDI.h"
#include "Marcador.h"



Marcador::Marcador() {//:sprite(vida, 4, 3) {
	// Relativo a los atributos
	//sprite.setCenter(1, 1);
	//sprite.setSize(3, 3); 
const 	char* p = "3";
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



	/*glPushMatrix();
	glTranslatef(ix, ij, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();*/
}
