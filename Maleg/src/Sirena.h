#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Sirena: public Enemigo
{
private:
	float salto_max;
	float salto_min;
	enum Estado { Show, Hide };
	Estado estado = Hide;
	
public:

	SpriteSequence mermaidUP, mermaidDOWN;

	Sirena();
	~Sirena();
	Sirena(float px, float py);
	void Salto(); 
	void Dibuja();
    void Mueve(float t);

	void ShowHitbox(bool e);
};

