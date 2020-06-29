#include "Mundo.h"
#include "Personaje.h"
#include "ETSIDI.h"
#include <iostream>
#include "glut.h"
using namespace std;

Mundo::Mundo() {
}


Mundo::~Mundo() {
	
}


void Mundo::Inicializa() {
	heroe.SetVida(3);
	nivel =3;
	CargarNivel();
	cout << "inicializa" << endl;

}


void Mundo::CargarNivel() {
	
	if (nivel == 1) {
		nivel1 = new Nivel1();
		nivel1->Inicializa(heroe);		
		cout << "Inicializamundonivel1" << endl;
	}
	else if (nivel == 2) {
		nivel2 = new Nivel2();
		nivel2->Inicializa(heroe);
		cout << "Inicializamundonivel2" << endl;
	}
	else if (nivel == 3) {
		nivel3 = new Nivel3();
		nivel3->Inicializa(heroe);
		cout << "Inicializamundonivel3" << endl;
	}
}


void Mundo::Dibuja() {
	////////////////////////////////Dibujar aqui
	if (nivel == 1){
		nivel1->Dibuja();
	}
	else if (nivel == 2) {
		nivel2->Dibuja();
	}
	else if (nivel == 3) {
		nivel3->Dibuja();
	}
}

void Mundo::TeclaEspecial(unsigned char key){

}

void Mundo::Mover(){
	if (nivel == 1) {
		if (nivel1->FinNivel1() == true) {
			cout << "ha acabado el nivel 1" << endl;
			nivel = nivel + 1;		
			heroe = nivel1->GetHeroe();
			nivel1->DestruirContenido();
			delete nivel1;
			cout << "Deletenivel1" << endl;
			CargarNivel();
		}
		else {
			nivel1->Mueve();
		}
	}

	if (nivel == 2) {
		if (nivel2->FinNivel2() == true) {
			cout << "ha acabado el nivel 2" << endl;
			nivel = nivel + 1;
			heroe = nivel2->GetHeroe();
			nivel2->DestruirContenido();
			delete nivel2;
			cout << "Deletenivel2" << endl;
			CargarNivel();
		}
		else {
			nivel2->Mueve();
		}
	}
	if(nivel == 3)
		if (nivel3->FinNivel3() == true) {
			cout << "ha acabado el nivel3" << endl;
			heroe = nivel3->GetHeroe();
			nivel3->DestruirContenido();
			delete nivel3;
			cout << "Deletenivel3" << endl;
		}
		else {
			nivel3->Mueve();
		}

	
}

void Mundo::Tecla(unsigned char key)
{	
	if(nivel==1)
		nivel1->Tecla(key);
	
	if(nivel==2)
		nivel2->Tecla(key);

	if (nivel == 3)
		nivel3->Tecla(key);
	
}
void Mundo::TeclaUp(unsigned char key) {
	if(nivel==1)
		nivel1->TeclaUp(key);
	
	if(nivel==2)
		nivel2->TeclaUp(key);

	if (nivel == 3)
		nivel3->TeclaUp(key);
}

bool Mundo::Muerte() {
	if (nivel == 1) {
		if (nivel1->MuerteHeroe()) {
			nivel1->DestruirContenido();
			delete nivel1;
			return true;
		}else if(!nivel1->MuerteHeroe()) {
			return false;
		}
	}
	else if (nivel == 2) {
		if (nivel2->MuerteHeroe()) {
			nivel2->DestruirContenido();
			delete nivel2;
			return true;
		}
		else if (!nivel2->MuerteHeroe()) {
			return false;
		}
	}
	else if (nivel == 3) {
		if (nivel3->MuerteHeroe()) {
			nivel3->DestruirContenido();
			delete nivel3;
			return true;
		}
		else if (!nivel3->MuerteHeroe()) {
			return false;
		}
	}
	
}
