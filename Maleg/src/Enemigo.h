#pragma once
#include "Personaje.h"
#define MAX_ENEM 20

class Enemigo: public Personaje
{
protected:
public: 
	Enemigo();
	virtual ~Enemigo();
	void Dibuja();
	virtual void Mueve(float t) {}
};

