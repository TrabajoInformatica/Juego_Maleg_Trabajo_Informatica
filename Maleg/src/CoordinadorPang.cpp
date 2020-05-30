#include "CoordinadorPang.h"
#include "ETSIDI.h"
#include "glut.h"


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
void CoordinadorPang::Tecla(unsigned char key) {
	if (estado == INICIO)
	{
		if (key == 's' || key == 'S')
		{

			mundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 'e' || key == 'E')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		if (key == 'p' || key == 'P')
			estado = PAUSA;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c' || key == 'C')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c' || key == 'C')
			estado = INICIO;
	}
	else if (estado == PAUSA) {
		if (key == 'c' || key == 'C')
			estado = JUEGO;
	}
}
void CoordinadorPang::Mueve() {}
void CoordinadorPang::Dibuja() {
	
	

}