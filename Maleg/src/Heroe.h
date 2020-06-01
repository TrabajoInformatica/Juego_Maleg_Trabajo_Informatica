#pragma once
#include <ETSIDI.h>
#include "Personaje.h"
using ETSIDI::SpriteSequence;
class Heroe: public Personaje
{
protected:
	float vida;
	float alturamuerte;
	SpriteSequence sprite;
public:
	Heroe();
	virtual ~Heroe();
	
	//METODOS SET
	void SetAlturaMuerte(float am);
	//METODOS GET
	virtual void Mueve(float t);
	virtual void Dibuja();
	//FUNCIONES
	bool Muerte();

};
