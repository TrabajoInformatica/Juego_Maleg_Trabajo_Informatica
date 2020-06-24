#pragma once
#include "Enemigo.h"
#define MAX_GUERR 5

class Guerreros: public Enemigo{

private:

public:
	Guerreros();
	Guerreros(float px, float py);
	~Guerreros();

	void Mueve(float t);
	void Dibuja();
};

