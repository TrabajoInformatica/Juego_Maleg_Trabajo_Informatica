#pragma once

#include "Enemigo.h"

class Araña: public Enemigo{

private:
	float lim_xi;
	float lim_xd;
	float lim_ya;
	float lim_yb;

public:
	Araña();
	Araña(float px, float py);
	~Araña();
	void Mueve(float t);
	void Movimiento();
	void Dibuja();
};

