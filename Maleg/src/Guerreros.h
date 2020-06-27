#pragma once
#include "Enemigo.h"
#define MAX_GUERR 5

class Guerreros: public Enemigo{

private:
	float lim_xd;
	float lim_xi;

public:
	Guerreros();
	Guerreros(float px, float py, float max, float v);
	~Guerreros();

	void Mueve(float t);
	void Dibuja();
	void Movimiento();
};

