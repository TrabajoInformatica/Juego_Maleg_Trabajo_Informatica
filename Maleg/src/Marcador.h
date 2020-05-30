#pragma once
#include "Personaje.h"
#include "Vector2D.h"
class Marcador
{
	char* vida;

public:
	Marcador();
	void Dibuja(Personaje *per);
};

