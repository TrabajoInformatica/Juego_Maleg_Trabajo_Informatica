#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"
#include "ObjetoMovil.h"

#define MAX_BOSS 1
using ETSIDI::SpriteSequence;

class Boss : public Enemigo
{
public:
	SpriteSequence boss;

	Boss();
	Boss(float x, float y);
	~Boss();

	void Mueve(float t);
	void Dibuja();

	bool AgregarB(Boss* b);

	int num;
	Boss* lista[MAX_BOSS];
};

