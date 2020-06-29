#pragma once
#include "Plataforma.h"
#include "Interaccion.h"

using ETSIDI::SpriteSequence;

class Puerta :public Plataforma
{
public:
	Puerta();
	~Puerta();
	Puerta(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a);
	void Dibuja();
	void DibujaP();
	void DestruirContenido();
	bool Colision(Heroe* p);
	
	bool AgregarP(Puerta* p);
	int num;
	Puerta* lista[2];

};
