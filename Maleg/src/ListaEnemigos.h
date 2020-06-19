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
	bool Agregar(Enemigo* e);
	void DestruirContenido();
	void Dibuja();
    void Mueve(float t);
	bool Colision(Heroe* p);
	void Eliminar(Enemigo* e);
	void Eliminar(int index);

private:
	Enemigo* Lista_e[MAX_ENEM];
	int nume;
};

