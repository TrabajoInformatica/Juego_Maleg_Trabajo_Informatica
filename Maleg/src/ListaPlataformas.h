#pragma once
#include "Plataforma.h"
#include "Bloque.h"
#include <string>
#include "Personaje.h"
using namespace std;
#define MAX_SIZE 100
class ListaPlataformas {
private:
	int numerop;
	Plataforma* Listap[MAX_SIZE];
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	void Dibuja();
	bool AgregarP(Plataforma* p);
	void LecturaFichero(string Fichero);
	void DestruirContenido();

	Plataforma GetListaPlat(int num);
	int GetNumPlat();

	void Colision(Personaje* p);

};
