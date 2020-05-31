#pragma once
#include "Plataforma.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Interaccion.h"
#include "Personaje.h"
#include "Fondo.h"

class Mundo {
	std::string direccion;
	Vector2D limite1;
	Vector2D limite2;
	float posZ;

public:
	
	Nivel1 nivel1;
	//Nivel2 nivel2;
	float x_ojo;
	float y_ojo;
	float z_ojo;
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

private:
	Fondo suelo;
};