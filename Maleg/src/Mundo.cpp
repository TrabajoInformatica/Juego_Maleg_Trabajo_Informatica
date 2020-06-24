#include "Mundo.h"
#include "Personaje.h"
#include "ETSIDI.h"
#include <iostream>
#include "glut.h"

Mundo::Mundo() {
}


Mundo::~Mundo() {
	
}


void Mundo::Inicializa() {
	vidaHeroe = 3;
	nivel =1;
	CargarNivel();
	cout << "inicializa" << endl;

}


void Mundo::CargarNivel() {
	
	if (nivel == 1) 
	{		
		nivel1->Inicializa(vidaHeroe);		
		cout << "Inicializamundonivel1" << endl;
	}
	else if (nivel == 2) {
		nivel2.Inicializa(vidaHeroe);
		cout << "Inicializamundonivel2" << endl;
	}
}


void Mundo::Dibuja() {
	////////////////////////////////Dibujar aqui
	if (nivel == 1){
		nivel1->Dibuja();
	}else if (nivel == 2) {
		nivel2.Dibuja();
	}
	if(nivel==1)
		vidaHeroe = nivel1->getVidaHeroe();	
}

void Mundo::TeclaEspecial(unsigned char key){
	/*switch (key)
	{
	case GLUT_KEY_LEFT:
		x_ojo = x_ojo - 1;
		break;
	case GLUT_KEY_RIGHT:
		x_ojo = x_ojo + 1;
		break;
	case GLUT_KEY_UP:
		y_ojo = y_ojo + 1;
		break;
	case GLUT_KEY_DOWN:
		y_ojo = y_ojo - 1;
		break;
	}*/
}

void Mundo::Mover(){
	if (nivel == 1) {
		if (nivel1->FinNivel1() == true) {
			cout << "ha acabado el nivel 1" << endl;
			nivel = nivel + 1;		
			nivel1->DestruirContenido();
			delete nivel1;
			cout << "Deletenivel1" << endl;
			CargarNivel();
		}
		else {
			nivel1->Mueve();
		}
	}
	
	if(nivel==2)
	nivel2.Mueve();
	
}

void Mundo::Tecla(unsigned char key)
{	
	if(nivel==1)
	nivel1->Tecla(key);
	
	if(nivel==2)
	nivel2.Tecla(key);
	
}
void Mundo::TeclaUp(unsigned char key) {
	if(nivel==1)
	nivel1->TeclaUp(key);
	
	if(nivel==2)
	nivel2.TeclaUp(key);
}

bool Mundo::Muerte() {
	if (nivel == 1) {
		if (nivel1->MuerteHeroe()) {
			return true;
		}else if(!nivel1->MuerteHeroe()) {
			return false;
		}
	}
	else if (nivel == 2) {
		if (nivel2.MuerteHeroe()) {
			return true;
		}
		else if (!nivel2.MuerteHeroe()) {
			return false;
		}
	}
	
}
