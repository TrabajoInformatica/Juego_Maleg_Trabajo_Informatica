#pragma once
#include "Personaje.h"
#define MAX_ENEM 20

class Enemigo: public Personaje{

private:

public: 
	Enemigo();
	virtual ~Enemigo();
	float GetRadio();
	virtual void Dibuja(){}
	virtual void  Mueve(float t){}
	virtual void ShowHitbox(bool e){}
	virtual void Colision(int t){}
};

