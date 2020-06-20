#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Arma :public ObjetoMovil
{
protected:
	float radio;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Arma();
	Arma(float px, float py, unsigned char r, unsigned char v, unsigned char a);//para inicializarlas
	~Arma();
	float GetRadio();
	void SetRadio(float r);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);

	virtual void Dibuja() {}
	virtual void Mueve(float t) {}
};