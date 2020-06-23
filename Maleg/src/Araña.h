#pragma once

#include "Enemigo.h"

class Ara�a: public Enemigo{

private:
	float lim_xi;
	float lim_xd;
	float lim_ya;
	float lim_yb;

public:
	Ara�a();
	Ara�a(float px, float py);
	~Ara�a();
	void Mueve(float t);
	void Movimiento();
	void Dibuja();
};

