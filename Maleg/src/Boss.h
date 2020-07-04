#pragma once
#include "Enemigo.h"
#include "ObjetoMovil.h"

#define MAX_BOSS 1

class Boss : public Enemigo
{
public:
	Boss();
	Boss(float x, float y);
	~Boss();

	void Mueve(float t);
	void Dibuja();

	bool AgregarB(Boss* b);

	int num;
	Boss* lista[MAX_BOSS];
};

