#pragma once
#include <iostream>
#include "Enemigo.h"
#include "ObjetoMovil.h"
#include "Heroe.h"
#include "Interaccion.h"
#include "ListaArmas.h"

using namespace std;

#define MAX_BOSS 1

class Boss : public Enemigo
{
public:
	Boss();
	Boss(float x, float y);
	~Boss();

	void Mueve(float t);
	void Dibuja();

	bool AgregarB(Boss* b);
	void DestruirContenido(Boss* b);

	void SetVida(int v);
	int GetVida();
	int vida;

	bool Colision(Heroe* p, Boss b);
	bool Colision(ListaArmas a, Boss b);

	int num;
	Boss* lista[MAX_BOSS];
};

