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
	if (velocidad.y > 10)
		velocidad.y = 10;
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
}
bool Heroe::Muerte() {
	
	if (alturamuerte >= posicion.y) {	
		vida -= 1;
		if(vida==0)
			return true;
		else {
			velocidad.y = 0;
			PuntoReaparicion();
			return false;
		}
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

void Heroe::PuntoReaparicion() {
	for (int i = 0;i < numeroRP;i++) {
		if (posicion.x < 0.0f){
		posicion.x = 0.0f;
		posicion.y = 0.0f;
		break;
		}
		else if (posicion.x < puntosR[i]->x) {
			Vector2D p = *(puntosR[i-=1]);
			posicion = p;
			break;
		}
	}
}

bool Heroe::AgregarPuntosR(Vector2D *p) {
	for (int i = 0;i < numeroRP;i++) {
		if ((puntosR[i]) == p)
			return false;
	}
	if (numeroRP < Max_Size)
		puntosR[numeroRP++] = p;
	else
		return false;
	return true;
}

void Heroe::DestruirContenido() {
	for (int i = 0;i < numeroRP;i++) {
		delete puntosR[i];
	}
	numeroRP = 0;
}