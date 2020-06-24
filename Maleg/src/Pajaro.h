#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Pajaro: public Enemigo{

private:
	float lim_xi;
	float lim_xd;
	float lim_yi;
	float lim_yd;

public:

	SpriteSequence sprite;

	Pajaro();
	Pajaro(float px, float py);
	~Pajaro();
	void Dibuja();
	void Mueve(float t);
	void Movimiento();
};

