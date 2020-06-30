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

class NivelFinal {
private:
	Heroe heroe;
	ListaPlataformas plataformas;        ///Objeto contiene todas las plataformas Nivel1
	string Fichero = "NivelFinal.txt";
	ListaMonedas monedas;
	ListaEnemigos enemigos;
	ListaArmas armas;
	ListaCorazones corazones;
	Puerta puerta;

	enum Estado { ShowHitbox, HideHitbox };
	Estado estado = HideHitbox;

public:
	Moneda moneda1;
	NivelFinal();
	virtual~NivelFinal();
	int vida;
	bool fin;
	Heroe GetHeroe();
	/////Funciones
	void Inicializa(Heroe h);
	bool FinNivelFinal();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char);
	void TeclaUp(unsigned char);

	bool MuerteHeroe();
	void DestruirContenido();

	void LecturaFichero(string Fichero);

};
/*
Plataforma horiz1;				//Horizontal1 Principio
Bloque esc1_p1;					//Escalera1 Pelda�o1
Bloque esc1_p2;					//Escalera1 Pelda�o2
Plataforma horiz2;				//Fin de la escalera, comienzo camino
Plataforma charco;				//Primera sirena
Plataforma horiz3;				//Suelo de tierra entre las sirenas
Plataforma charco2;				//Suelo donde se encuentran las dos sirenas
Plataforma elevada;				//Suelo elevada encima de las dos sirenas
Plataforma horiz4;				//Suelo despues de las 2 sirenas
Bloque cuadrado1;					//SaltosCuadrados1 cuadrado1
Bloque cuadrado2;					//SaltosCuadrados1 cuadrado2
Plataforma horiz5;						//Plataforma despues de los cuadrados de salto con pajaro encima y agua debajo
Plataforma horiz6;						//Agua debajo de plataforma de pajaros
Plataforma horiz7;						//Salto1 encima del agua despues de plataforma pajaros
Plataforma horiz8;						//Salto2
Plataforma horiz9;						//Salto3

Plataforma horiz10;					//Plataforma1 despues de saltos
Plataforma horiz11;						//Plataforma2
Plataforma horiz12;						//Plataforma3
Bloque paredvertical;					//Pared vertical despues de platforma3
Plataforma horiz13;						//Cueva techo
Plataforma horiz14;						//Cueva suelo
*/