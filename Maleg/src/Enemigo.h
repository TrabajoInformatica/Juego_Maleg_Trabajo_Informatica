#pragma once
#include <iostream>
#include "Personaje.h"
#define MAX_ENEM 50

using namespace std;

class Enemigo: public Personaje{

protected:

public: 
	Enemigo();
	virtual ~Enemigo();
	float GetRadio();
	virtual void Dibuja(){}
	virtual void  Mueve(float t){}

	/*void SetVida(int v);
	int GetVida();*/
	int vida;

	bool Muerte();
};

