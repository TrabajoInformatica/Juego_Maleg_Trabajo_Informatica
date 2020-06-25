#pragma once
#include "VidaExtra.h"
#include "Interaccion.h"

#define MAX_COR 3
class ListaCorazones
{
public:
	ListaCorazones();
	~ListaCorazones();
	bool AgregarC(VidaExtra* v);
	void DestruirContenido();
	void Dibuja();
	void Mueve(float t);
	bool Colision(Heroe* p);

	void Eliminar(VidaExtra* v);
	void Eliminar(int index);

	void ShowHitbox(bool e);//no esta implementada

private:
	VidaExtra* Lista_c[MAX_COR];
	int num;
};

