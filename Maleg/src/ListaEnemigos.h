#pragma once
#include "Sirena.h"
#include "Pajaro.h"
#include "Guerreros.h"
#include "Araña.h"
#include "Enemigo.h"
#include "Interaccion.h"
class ListaEnemigos{

public:
	ListaEnemigos();
	~ListaEnemigos();
	bool AgregarE(Enemigo* e);
	Enemigo GetListaEnem(int num);
	void DestruirContenido();
	int GetNumeroE();
	void Dibuja();
    void Mueve(float t);
	bool Colision(Heroe* p);
	void Colision(Plataforma pl);

	void Eliminar(Enemigo* e);
	void Eliminar(int index);

	void ShowHitbox(bool e);

private:
	Enemigo* Lista_e[MAX_ENEM];
	int nume;
};

