#pragma once
#include "Arma.h"

class Lanza : public Arma {
protected:

public:
	Lanza(float x,float y);
	virtual ~Lanza();

	void Dibuja();
	void Mueve(float t);
};