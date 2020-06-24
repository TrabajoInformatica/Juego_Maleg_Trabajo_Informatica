#pragma once
#include "ObjetoMovil.h"
#include "Interaccion.h"
class VidaExtra: public ObjetoMovil
{
private:
	
public:
	VidaExtra();
	~VidaExtra();
	void Dibuja();
	void Mueve(float t,float dist);

	
	bool ColisionVida(Heroe* p, VidaExtra v);
};

