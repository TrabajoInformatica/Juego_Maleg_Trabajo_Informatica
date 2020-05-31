#pragma once
#include "Enemigo.h"
#define MAX_ENEM 5

class Sirena: public Enemigo
{
private:
	float salto_max;
	float salto_min;
public:
	Sirena();
	~Sirena();

	void Salto(Sirena &s);
};

