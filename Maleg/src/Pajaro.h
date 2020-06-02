#pragma once
#include "Enemigo.h"
#define MAX_PAJARO 5

class Pajaro: public Enemigo{
	float salto_max;
	float salto_min;
public:
	Pajaro();
	Pajaro(float px, float py);
	~Pajaro();

	void Mueve(float t);
};

