#include "Mundo.h"
#include "Personaje.h"
#include "ETSIDI.h"
#include <iostream>
#include "glut.h"

Mundo::Mundo() {
	vidaHeroe = 4;
	nivel = 1;
}


Mundo::~Mundo() {
	
}


void Mundo::Inicializa() {
	//x_ojo = 0;
	//y_ojo = 7.5;
	//z_ojo = 30;
	nivel = 0;
	CargarNivel();
	cout << "inicializa" << endl;

	//nivel1.Inicializa(vidaHeroe);
	//nivel2.Inicializa();
}


void Mundo::CargarNivel() {
	nivel++;
	//nivel1.DestruirContenido();
	
	if (nivel == 1) 
	{
		cout << "nivel1" << endl;
		nivel1.Inicializa(vidaHeroe);
		
		
	}
	else if (nivel == 2) {
		//nivel2.Inicializa();
		nivel1.DestruirContenido();
		cout << "nivel2" << endl;
	}
}


void Mundo::Dibuja() {
	////////////////////////////////Dibujar aqui
	//ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	//ETSIDI::printxy("Bienvenido al pang. ", -5, 8);
	
		nivel1.Dibuja();
		vidaHeroe = nivel1.getVidaHeroe();
	
	//nivel2.Dibuja();
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
	if (nivel1.FinNivel1() == true) {
		cout << "ha acabado el nivel 1" << endl;
		CargarNivel();

	}
	nivel1.Mueve();
	//nivel2.Mueve();
}

void Mundo::Tecla(unsigned char key)
{
	nivel1.Tecla(key);
	//nivel2.Tecla(key);
}
void Mundo::TeclaUp(unsigned char key) {
	nivel1.TeclaUp(key);
}

bool Mundo::Muerte() {
	if (nivel == 1) {
		if (nivel1.MuerteHeroe()) {
			return true;
		}else if(!nivel1.MuerteHeroe()) {
			return false;
		}
	}
	/*else if (nivel == 2) {
		if (Aqui iria nivel2.Muerteheroe abria que definirla todavia para otro momento cuando se empieze a editar nivel 2) {
			return true;
		}
		else if () {
			return false;
		}
	}
	*/	
}
