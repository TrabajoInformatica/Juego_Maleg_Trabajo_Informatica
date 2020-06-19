#pragma once
#include "Sirena.h"
#include "Pajaro.h"
#include "Guerreros.h"
#include "Enemigo.h"
#include "Interaccion.h"
class ListaEnemigos{

public:
	ListaEnemigos();
	~ListaEnemigos();
	bool AgregarEnem(Enemigo* e);
	void DestruirContenido();
	void Dibuja();
	virtual void Mueve(float t);
	bool Colision(Heroe* p);
	void Eliminar(Enemigo* e);
	void Eliminar(int index);

private:
	Enemigo* lista_e[MAX_ENEM];
	int nume;
};

