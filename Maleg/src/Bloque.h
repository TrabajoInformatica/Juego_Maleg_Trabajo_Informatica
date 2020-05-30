#pragma once
#include "Vector2D.h"
#include "Plataforma.h"
class Bloque : public Plataforma {
private:

public:
	Bloque();
	Bloque(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a);
	virtual ~Bloque();
	void Dibuja();
};