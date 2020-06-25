#pragma once
#pragma once
#include "ListaPlataformas.h"
#include "ListaMonedas.h"
#include "ListaEnemigos.h"
#include "ListaArmas.h"
#include "ListaCorazones.h"
#include <string>
#include "Heroe.h"
#include "Sirena.h"
#include "Lanza.h"
#include "Puerta.h"
#include "Interaccion.h"

using namespace std;

class Nivel3 {
private:
	Heroe heroe3;
	ListaPlataformas plataformas3;        ///Objeto contiene todas las plataformas Nivel1
	string Fichero = "Nivel1.txt";
	ListaMonedas monedas3;
	ListaEnemigos enemigos3;
	ListaArmas armas3;
	ListaCorazones corazones3;
	Puerta puerta;
	enum Estado { ShowHitbox, HideHitbox };
	Estado estado = HideHitbox;

public:
	Moneda moneda1;
	Nivel3();
	virtual~Nivel3();
	int vida;
	bool fin;
	Heroe GetHeroe();
	/////Funciones
	void Inicializa(Heroe h);
	bool FinNivel3();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char);
	void TeclaUp(unsigned char);

	bool MuerteHeroe();
	void DestruirContenido();

	void LecturaFichero(string Fichero);

};
