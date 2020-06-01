#pragma once
#include "Enemigo.h"
#define MAX_SIRENA 5

class Sirena: public Enemigo
{
private:
	float salto_max;
	float salto_min;
public:
	Sirena();
	~Sirena();
	Sirena(float px, float py);//para inicializarlas
	void Salto(); //intento de mov hacia arriba y abajo en bucle
};

