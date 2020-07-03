#include "Boton.h"
#include "Interaccion.h"
#include <iostream>
#include "glut.h"

using namespace std;

Boton::Boton() { //: button("imagenes/boton.png", 6, 1) 
	rojo = 255;
	verde = azul = 0;
	radio = 1;
}
Boton::Boton(float px, float py, float rad, unsigned char r, unsigned char v, unsigned char a) { //: button("imagenes/boton.png", 6, 1) 

	posicion.x = px;
	posicion.y = py;
	rojo = r;
	verde = v;
	azul = a;
	radio = rad;
}
Boton::~Boton() {

}


void Boton::Dibuja() {
	//Dimensiones del sprite
	/*button.setCenter(0.5, 0.5);
	button.setSize(1, 1);*/

	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	//button.draw();
	//button.loop();
	glPopMatrix();

	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);

}
bool Boton::Colision(Heroe* p, Boton& b) {
	if (Interaccion::ColisionBoton(p, b))
	{
		cout << "colision boton" << endl;
		return true;
		ETSIDI::play("sonidos/estruendo.wav");
	}

	return false;
}

void Boton::DestruirContenido(Boton* b) {

	delete b;

}
