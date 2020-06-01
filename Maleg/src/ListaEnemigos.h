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
	bool AgregarSire(Sirena* s);
	bool AgregarPaja(Pajaro* p);
	bool AgregarGue(Guerreros* g);
	void DestruirContenido();
	void Dibuja();
	void Mueve(float t);
	Enemigo* Colision(Personaje* p);
	void Eliminar(Enemigo* e);
	void Eliminar(int index);

private:
	Sirena* lista_s[MAX_SIRENA];
	Pajaro* lista_p[MAX_PAJARO];
	Guerreros* lista_g[MAX_GUERR];
	int nums;
	int numg;
	int nump;
};

