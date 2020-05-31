#include "CoordinadorPang.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>

using namespace std;

CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;

}


CoordinadorPang::~CoordinadorPang()
{
}

void CoordinadorPang::TeclaEspecial(unsigned char key) {
	if (estado == JUEGO)
		mundo.TeclaEspecial(key);

}
void CoordinadorPang::Tecla(unsigned char key) 
{
	if (estado == INICIO)
	{
		if (key == 's' || key == 'S')
		{
			cout << "INTRO" << endl;
			estado = INTRO;
		}
		else if (key == 'e' || key == 'E') 
			exit(0);
	}
	else if (estado == INTRO) 
	{
		if (key == 'p') 
		{
			estado = CARGA;
			cout << "CARGA" << endl;
		}
	}
	else if (estado == CARGA) 
	{
		if (key == 'c' || key == 'C')
		{
			mundo.Inicializa();
			estado = JUEGO;
			cout << "JUEGO" << endl;
		}
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		if (key == 'p' || key == 'P')
			estado = PAUSA;
	}

	else if (estado == GAMEOVER)
	{
		if (key == 'c' || key == 'C') {
			mundo.resetNiv(); //Reseto los niveles, y vuelvo a Inicio
								
			estado = INICIO;
			
		}
		else if (key == 'e' || key == 'E')
			exit(0);
	}
	else if (estado == FIN)
	{
		if (key == 'c' || key == 'C') {

			mundo.resetNiv();

			estado = INICIO;

		}
		else if (key == 'e' || key == 'E')
			exit(0);
	}

	else if (estado == PAUSA) 
	{
		if (key == 'c' || key == 'C')
			estado = JUEGO;
		else if (key == 'e' || key == 'E')
		{
			mundo.resetNiv();

			estado = INICIO;


		}
	}
}
void CoordinadorPang::Mueve() 
{
	//mundo.Mover();
}
void CoordinadorPang::Dibuja() 
{
	
	if (estado == INICIO)
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		//fondo a la pantalla de incicio
		pantalla.setPos("imagenes/portada.png", -14.5, -3.5, 14.5, 18.5, 0.0);
		pantalla.Dibuja();
	}
	if (estado == JUEGO)
	{
		mundo.Dibuja();
	}
}