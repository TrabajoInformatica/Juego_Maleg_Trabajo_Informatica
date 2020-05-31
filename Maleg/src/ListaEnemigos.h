#pragma once
#include "Sirena.h"
#include "Pajaro.h"
#include "Guerreros.h"
#include "Enemigo.h"

class ListaEnemigos{

public:
	ListaEnemigos();
	~ListaEnemigos();
	bool Agregar(Sirena* s);
	bool Agregar(Pajaro* p);
	bool Agregar(Guerreros* g);
	void DestruirContenido();
	void Dibuja();
	void Mueve(float t);
	void Eliminar(Enemigo* e);
	void Eliminar(int index);

private:
	Sirena* lista_s[MAX_SIRENA];
	Pajaro* lista_p[MAX_PAJARO];
	Guerreros* lista_g[MAX_GUERR];
	int num;
};

