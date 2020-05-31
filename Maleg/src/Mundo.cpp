#include "Mundo.h"
#include "Personaje.h"
#include "ETSIDI.h"
#include "glut.h"

Mundo::Mundo() {
}

Mundo::~Mundo() {
	
}


void Mundo::Inicializa() {
	x_ojo = 0;
	y_ojo = 7.5;
//	z_ojo = 30;
	//nivel = 0;
	//CargarNivel();

	nivel1.Inicializa();
}


void Mundo::CargarNivel() {
	nivel++;
	if (nivel == 1) {
		nivel1.Inicializa();
		nivel1.Dibuja();
	}
	//nivel2.Inicializa();
}


void Mundo::Dibuja() {
	////////////////////////////////Dibujar aqui
	//ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	//ETSIDI::printxy("Bienvenido al pang. ", -5, 8);
	nivel1.Dibuja();
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
	nivel1.mueve(0.025f);
	//nivel2.mueve(0.025f);
}

void Mundo::Tecla(unsigned char key)
{
	nivel1.Tecla(key);
}

