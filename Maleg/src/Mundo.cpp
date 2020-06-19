#include "Mundo.h"
#include "Personaje.h"
#include "ETSIDI.h"
#include <iostream>
#include "glut.h"

Mundo::Mundo() {
	vidaHeroe = 4;
}


Mundo::~Mundo() {
	
}


void Mundo::Inicializa() {
	//nivel = 0;
	//CargarNivel();

	nivel1.Inicializa();
	//nivel2.Inicializa();
	nivel1.SetVidaHeroe(vidaHeroe);
}


void Mundo::CargarNivel() {
	nivel+=1;
	if (nivel == 1) {
		//nivel1.Inicializa();
		//nivel1.Dibuja();
	}
	if (nivel == 2) {
		//nivel2.Inicializa();
	}
}


void Mundo::Dibuja() {
	////////////////////////////////Dibujar aqui
	//ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	//ETSIDI::printxy("Bienvenido al pang. ", -5, 8);
	nivel1.Dibuja();
	vidaHeroe=nivel1.getVidaHeroe();
	cout << vidaHeroe << endl;
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
