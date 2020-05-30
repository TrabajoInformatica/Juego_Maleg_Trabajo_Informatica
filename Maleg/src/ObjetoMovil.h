#pragma once
#include "Vector2D.h"

class ObjetoMovil
{
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	void Mueve(float t);
	void SetAce(float ax, float ay);
	void SetPos(float x, float y);
	void SetVel(float vx, float vy);

	Vector2D GetVel();
	Vector2D GetPos();
};

