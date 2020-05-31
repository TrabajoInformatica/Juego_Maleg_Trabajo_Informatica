#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Moneda
{
private:
	float radio;
	float radio_min;
	float radio_max;
	float pulso;

	Vector2D posicion;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Moneda();
	Moneda(float px, float py);//para inicializarlas
	~Moneda();
	float GetRadio();
	void SetRadio(float r);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float posx, float posy);
	Vector2D GetPos();
	void Dibuja();
	void Mueve(float t);
};
