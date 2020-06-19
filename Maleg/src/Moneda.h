#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Moneda:public ObjetoMovil
{
private:
	float radio;
	float radio_min;
	float radio_max;
	float pulso;

	
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Moneda();
	Moneda(float px, float py,float radio,unsigned char r,unsigned char v,unsigned char a);//para inicializarlas
	~Moneda();
	float GetRadio();
	void SetRadio(float r);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);

	void Dibuja();
	void Mueve(float t);
};
