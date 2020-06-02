#pragma once
#include "Enemigo.h"
#define MAX_PAJARO 5

class Pajaro: public Enemigo{

public:
	Pajaro();
	~Pajaro();
	Pajaro(float px, float py);
	void Mueve();
};

