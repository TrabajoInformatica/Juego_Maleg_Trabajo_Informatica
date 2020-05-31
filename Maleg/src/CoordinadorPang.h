#pragma once

#include "Mundo.h"
#include "Fondo.h"


class CoordinadorPang
{
public:
	CoordinadorPang();
	virtual ~CoordinadorPang();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();

protected:
	Fondo pantalla;
	Mundo mundo;
	enum Estado { INICIO, INTRO, CARGA, JUEGO, GAMEOVER, FIN, PAUSA }; //Fin el cuando se acaba el juego, GameOver cuando el jugador ha perdido
	Estado estado;
};