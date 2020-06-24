#pragma once
#include "Personaje.h"
#define MAX_ENEM 50

class Enemigo: public Personaje{

protected:

public: 
	Enemigo();
	virtual ~Enemigo();
	float GetRadio();
	virtual void Dibuja(){}
	virtual void  Mueve(float t){}
};

