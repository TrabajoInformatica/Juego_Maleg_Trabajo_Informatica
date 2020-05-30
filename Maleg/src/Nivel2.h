#pragma once
#include "ListaPlataformas.h"
#include "ListaMonedas.h"
#include <string>
using namespace std;

class Nivel2 {
private:
	ListaPlataformas plataformas;        //Objeto contiene todas las plataformas Nivel1
	string Fichero = "Nivel2.txt";
	ListaMonedas monedas2;
public:
	Nivel2();
	virtual ~Nivel2();
	void mueve(float t);
	void Inicializa();
	void Dibuja();


	
	/*Plataforma hor1; //Plataforma base inicial
	Bloque blo1; //Primer bloque en la primera pared vertical
	Plataforma flot1; //Primera plataforma flotante
	Bloque blo2; //Segundo bloque en la pared vertical
	Plataforma flot2; //Segunda plataforma flotante
	Plataforma ver1; //Primera pared vertical 
	Plataforma hor2; //Continuaci�n despues de los saltos
	Plataforma hoyo; //Cavidad en el suelo
	Plataforma flot3; //Plataforma flotante encima del suelo
	Bloque blo3; //Bloque flotante
	Bloque blo4; //Bloque flotante a continuaci�n del anterior
	Bloque blo5; //Bloque flotante a continuaci�n del anterior
	Plataforma hor3; //Zona de "descanso" despu�s de los saltos 
	Plataforma hoyo2; //Hoyo debajo de la plataforma anterior
	Plataforma hor4; //Plataforma
	Bloque esc1; //Pelda�os de las escaleras
	Bloque esc2;
	Bloque esc3;
	Bloque esc4;
	Bloque esc5; 
	Bloque esc6;
	Plataforma ver3; //Cierre de la escalera
	Bloque blo6; //Rectangulo grande
	Plataforma hoyo3; //Hoyo a continuacion del rectangulo
	Plataforma hor5;
	Plataforma flot4;//Plataformas flotantantes
	Plataforma flot5;
	Plataforma flot6;
	Bloque blo7; //Bloque*/


	
};