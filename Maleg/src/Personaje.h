#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "glut.h"

class Personaje:public ObjetoMovil
{
protected:
	float altura;
	unsigned char rojo, verde, azul;
	enum Estado { Show, Hide };
	Estado estado = Hide;

public:
	Personaje();
	virtual~Personaje();
	
	void SetAltura(float a);
	float GetAltura();
	void DestruirContenido();
	void ShowHitbox(bool e);
};

