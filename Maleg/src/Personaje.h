#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "glut.h"

class Personaje:public ObjetoMovil
{
protected:
	float altura;
	unsigned char rojo, verde, azul;

public:
	Personaje();
	virtual~Personaje();
	

	void SetAltura(float a);
	float GetAltura();

	virtual void Dibuja();
	void DestruirContenido();
};

