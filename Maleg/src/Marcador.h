#pragma once
#include <ETSIDI.h>
#include "Personaje.h"
#include "Vector2D.h"
#include "ObjetoMovil.h"
//using ETSIDI::SpriteSequence;
class Marcador: public ObjetoMovil
{
	char* vida;
//	SpriteSequence sprite;

public:
	Marcador();
	void Dibuja(Personaje *per);
};

