#pragma once
#include "Enemigo.h"

class Murcielago: public Enemigo{

private:
	float lim_xd;
	float lim_xi;
	float lim_ya;
	float lim_yb;

public:
	Murcielago();
	Murcielago(float px, float py);
	~Murcielago();
	void Dibuja();
	void Mueve(float t);
	void Movimiento();

};

