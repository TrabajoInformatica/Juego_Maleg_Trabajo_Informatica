#pragma once
#include <ETSIDI.h>
#include "Personaje.h"
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Heroe: public Personaje{
protected:
	float vida;
	float alturamuerte;

	SpriteSequence sprite, salto;

public:
	Heroe();
	virtual ~Heroe();

	//METODOS GET
	virtual void Mueve(float t);
	virtual void Dibuja();

	//METODOS SET
	void SetAlturaMuerte(float am);
	void SetVida( float v);

	//ANIMACIONES
	void AnimationRun();
	void AnimationJump();
	//FUNCIONES
	bool Muerte();
};
