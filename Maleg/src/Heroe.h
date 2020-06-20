#pragma once
#include <ETSIDI.h>
#include "Personaje.h"
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Heroe: public Personaje{
protected:
	float vida;
	float alturamuerte;

	SpriteSequence run, jumpUP, jumpDOWN;

public:
	Heroe();
	virtual ~Heroe();

	//METODOS GET
	int GetVida();

	//METODOS SET
	void SetAlturaMuerte(float am);
	void SetVida( float v);

	//ANIMACIONES
	virtual void Dibuja();
	virtual void Mueve(float t);

	//FUNCIONES
	bool Muerte();
};
