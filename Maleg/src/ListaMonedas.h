#pragma once
#include "Moneda.h"
#include "Personaje.h"
#include "Interaccion.h"
#define MAX_MON 5
class ListaMonedas
{
public:
	ListaMonedas();//constructor
	virtual ~ListaMonedas();//destructor
	bool agregar(Moneda* m);
	void destruirContenido();
	void Dibuja();
	void Mueve(float t);
	void Colision(Personaje* p);


private:
	Moneda* lista[MAX_MON];//puntero a monedaa
	int numero;
};

