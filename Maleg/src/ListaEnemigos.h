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
	bool AgregarSire(Sirena* s);
	bool AgregarPaja(Pajaro* p);
	bool AgregarGue(Guerreros* g);
	void DestruirContenido();
	//void Dibuja();
	//void Mueve(float t);
	//bool Colision(Personaje* p);
	void Eliminar(Enemigo* e);

	void DestruirEnemigos();
	void Eliminar(int index);
	void Dibuja();
	void Mueve(float t);
	bool Agregar(Enemigo* e);
	void Colision(Heroe* p);

private:
	Enemigo* Listae[MAX_SIZE];
	Sirena* lista_s[MAX_SIRENA];
	Pajaro* lista_p[MAX_PAJARO];
	Guerreros* lista_g[MAX_GUERR];
	int nums;
	int numg;
	int nump;
	int numeroe;
};

