#include "CoordinadorPang.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>

using namespace std;

CoordinadorPang::CoordinadorPang(){
	estado = INICIO;
}


CoordinadorPang::~CoordinadorPang(){
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
		if (key == ' ') 
		{
			estado = CARGA;
			mundo.CargarNivel();
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
	if (estado == JUEGO)
	{
		mundo.Mover();
	}
}
void CoordinadorPang::Dibuja() 
{
	
	if (estado == INICIO)
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/portada.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, 0, 0);
		glTexCoord2d(1, 1); glVertex3f(15, 0, 0); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, 0);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 0, 0); //r g b
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("MY GAME", -12, 14);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pulsa S (Start)", -12, 13);
		ETSIDI::printxy("Pulsa E (Exit)", -12, 12); //const char* txt ,int x,int y,int z=0
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::setTextColor(0.7f, 0.1f, 0.1f); //r g b
		ETSIDI::printxy("----------------", 0, 7);
		
	}
	if (estado == JUEGO)
	{
		mundo.Dibuja();
	}
	
}