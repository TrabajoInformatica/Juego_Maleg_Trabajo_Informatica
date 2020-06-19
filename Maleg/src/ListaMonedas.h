#pragma once
#include "Moneda.h"
#include "Personaje.h"
#include "Interaccion.h"
#include <string>
using namespace std;
#define MAX_MON 10
class ListaMonedas
{
public:
	ListaMonedas();//constructor
	virtual ~ListaMonedas();//destructor
	bool AgregarM(Moneda* m);
	void destruirContenido();
	void Dibuja();
	void Mueve(float t);
	Moneda* Colision(Heroe* p);
	void Eliminar(Moneda* e);
	void Eliminar(int index);

private:
	Moneda* lista[MAX_MON];//puntero a monedaa
	int numero;
};

