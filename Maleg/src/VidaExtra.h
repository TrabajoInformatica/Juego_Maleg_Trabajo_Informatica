#pragma once
#include "ObjetoMovil.h"
class VidaExtra : public ObjetoMovil
{
private:
	float posicionfin;
public:
	VidaExtra();
	VidaExtra(float px, float py, float posfin,float r,float vy);
	~VidaExtra();
	void Dibuja();
	void Mueve(float t);

};
