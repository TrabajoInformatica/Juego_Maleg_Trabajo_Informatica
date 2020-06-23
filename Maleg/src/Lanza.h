#pragma once
#include "Arma.h"

class Lanza : public Arma {
protected:

public:
	Lanza(float x,float y,float v);
	virtual ~Lanza();

	void Dibuja();
	void Mueve(float t);
};