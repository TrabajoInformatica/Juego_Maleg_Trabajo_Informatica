#pragma once
#include "Personaje.h"
#include "Enemigo.h"

class Heroe: public Personaje
{
protected:
	float vida;
	float alturamuerte;
	
	
public:
	Heroe();
	virtual ~Heroe();
	
	//METODOS SET
	void SetAlturaMuerte(float am);
	void SetVida( float v);
	//METODOS GET
	
	//FUNCIONES
	bool Muerte();

};
