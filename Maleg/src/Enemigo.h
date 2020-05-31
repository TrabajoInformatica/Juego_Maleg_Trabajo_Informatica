#pragma once
#include "Personaje.h"
#define MAX_ENEM 20

class Enemigo: public Personaje
{
public: 
	Enemigo();
	virtual ~Enemigo();
	Enemigo(float x, float y); //??
	void Dibuja();
};

