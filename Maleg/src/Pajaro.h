#pragma once
#include "Enemigo.h"
#define MAX_PAJARO 5

class Pajaro: public Enemigo{

private:
	float lim_xi;
	float lim_xd;
	float lim_yi;
	float lim_yd;


public:
	Pajaro();
	Pajaro(float px, float py);
	~Pajaro();
	void Movimiento();
	//virtual void Mueve(float t);
};

