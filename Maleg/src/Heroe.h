#pragma once
#include "Personaje.h"

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
	//METODOS GET
	
	//FUNCIONES
	bool Muerte();

};
