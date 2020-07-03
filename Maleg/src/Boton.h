#pragma once
#include <ETSIDI.h>
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "Personaje.h"
using ETSIDI::SpriteSequence;

class Boton :public ObjetoMovil
{
private:

	float radio;

public:

	SpriteSequence button;
	Boton();
	Boton(float px, float py, float radio, unsigned char r, unsigned char v, unsigned char a);//para inicializarlas
	~Boton();

	void Colision(Heroe* p);
	void Dibuja();
};
