#pragma once
#include "Enemigo.h"

class Boss : public Enemigo
{
	Boss(float x, float y);
	~Boss();

	void Mueve(float t);
	void Dibuja();


};

