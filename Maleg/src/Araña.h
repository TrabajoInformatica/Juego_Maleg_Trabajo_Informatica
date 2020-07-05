#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Ara�a: public Enemigo{
private:
	float lim_xi;
	float lim_xd;
	float lim_ya;
	float lim_yb;


public:
	SpriteSequence spyder;

	Ara�a();
	Ara�a(float px, float py);
	Ara�a(float px, float py, float limitex, float limitey);
	~Ara�a();
	void Mueve(float t);
	void Movimiento();
	void Dibuja();
};

