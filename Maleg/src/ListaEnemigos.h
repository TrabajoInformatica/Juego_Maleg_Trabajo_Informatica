#pragma once
#include "Heroe.h"
#include "Sirena.h"
#include "Pajaro.h"
#include "Guerreros.h"
#include "Enemigo.h"
#include "Interaccion.h"

#define MAX_SIZE 100
class ListaEnemigos{

public:
	ListaEnemigos();
	~ListaEnemigos();

	void DestruirEnemigos();
	void Dibuja();
	void Mueve(float t);
	bool Agregar(Enemigo* e);
	void Colision(Heroe* p);

private:
	Enemigo* Listae[MAX_SIZE];
	int numeroe;
};

