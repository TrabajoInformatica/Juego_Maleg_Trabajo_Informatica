#pragma once
#include "Mundo.h"

class CoordinadorPang
{
public:
	CoordinadorPang();
	virtual ~CoordinadorPang();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void TeclaUp(unsigned char key);
	void Mueve();
	void Dibuja();
	
protected:
	Mundo mundo;
	enum Estado { INICIO, INTRO, CARGA, JUEGO, GAMEOVER, FIN, PAUSA }; //Fin el cuando se acaba el juego, GameOver cuando el jugador ha perdido
	Estado estado;
};