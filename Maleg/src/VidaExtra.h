#pragma once
#include "ObjetoMovil.h"
class VidaExtra : public ObjetoMovil
{
private:

public:
	VidaExtra();
	~VidaExtra();
	void Dibuja();
	void Mueve(float t, float dist);

};
