#pragma once
#include "Personaje.h"
#define MAX_ENEM 20

class Enemigo: public Personaje{

private:
	float salto_max;
	float salto_min;
public: 
	Enemigo();
	virtual ~Enemigo();
	Enemigo(float x, float y); //??
	float GetRadio();
	void Dibuja();
	
};

