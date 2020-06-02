#pragma once
#include "Enemigo.h"

class Sirena: public Enemigo
{
private:
	float salto_max;
	float salto_min;
public:
	Sirena();
	Sirena(float x,float y);
	
~Sirena();
	void Salto(); //intento de mov hacia arriba y abajo en bucle
	void Mueve(float t);
};

