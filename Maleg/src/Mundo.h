#pragma once
#include "Plataforma.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Interaccion.h"
#include "Personaje.h"

class Mundo {
	public:
	
	Nivel1 nivel1;
	//Nivel2 nivel2;
	int nivel;
		Mundo();
virtual ~Mundo();

void Inicializa();
void Dibuja();
void TeclaEspecial(unsigned char key);
void Mover();
//void RotarOjo();

void CargarNivel();
void resetNiv() { nivel = 0; }

void Tecla(unsigned char key);

bool Muerte();


};