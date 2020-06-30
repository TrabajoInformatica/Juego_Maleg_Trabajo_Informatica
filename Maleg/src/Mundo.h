#pragma once
#include "Plataforma.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "NivelFinal.h"
#include "Interaccion.h"
#include "Personaje.h"

class Mundo {
public:
	Heroe heroe;
	Nivel1* nivel1;
	Nivel2* nivel2;
	Nivel3* nivel3;
	NivelFinal* nivelfinal;
	int nivel;
		Mundo();
virtual ~Mundo();

void Inicializa();
void Dibuja();
void TeclaEspecial(unsigned char key);
void Mover();

void CargarNivel();
void resetNiv() { nivel = 0; }

void Tecla(unsigned char key);
void TeclaUp(unsigned char key);

bool Muerte();


};