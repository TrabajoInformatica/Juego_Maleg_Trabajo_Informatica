#pragma once
#include "Vector2D.h"
#include "Plataforma.h"
#include "Heroe.h"
class Bloque : public Plataforma{
private:
	int contador;
	Vector2D velocidad;
public:
	Bloque();
	Bloque(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a);
	virtual ~Bloque();
	void Mueve(float t);
	void Dibuja();
	void Reaccion(Heroe *pers);
};