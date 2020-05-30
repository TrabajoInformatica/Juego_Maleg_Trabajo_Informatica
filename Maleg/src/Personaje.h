#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "glut.h"

class Personaje:public ObjetoMovil
{
public:
	Personaje();
	virtual~Personaje();
	void Dibuja();
	void Destruircontenido();
	void SetAltura(float a);
	float GetAltura();

protected:
	float altura;
	unsigned char rojo, verde, azul;
};

