#pragma once
#include "ListaPlataformas.h"
#include "ListaMonedas.h"
#include "ListaEnemigos.h"
#include "Marcador.h"
#include <string>
#include "Heroe.h"
#include "Sirena.h"
#include "Interaccion.h"
#define MAX_SIZE

using namespace std;

class Nivel1 {
private:
	Heroe heroe;
	ListaPlataformas plataformas;        ///Objeto contiene todas las plataformas Nivel1
	string Fichero = "Nivel1.txt";
	ListaMonedas monedas;
	ListaEnemigos sirenas;
	ListaEnemigos pajaros;
	Sirena sirena;
	Pajaro pajaro;
	//Personaje persona;
	Marcador marcador;
	
	
public:
	Moneda moneda1;
	Nivel1();
	virtual~Nivel1();
	int vida;
	int getVidaHeroe();
	void SetVidaHeroe(int vidas);
	/////Funciones
	void Inicializa();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char);
	int salto = 3;

	bool MuerteHeroe();
	friend class Mundo;

};
/*
Plataforma horiz1;				//Horizontal1 Principio
Bloque esc1_p1;					//Escalera1 Peldaño1
Bloque esc1_p2;					//Escalera1 Peldaño2
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