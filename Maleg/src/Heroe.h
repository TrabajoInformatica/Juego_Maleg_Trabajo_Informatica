#pragma once
#include <ETSIDI.h>
#include "Personaje.h"
#include "Enemigo.h"

#define Max_Size 10			//Numero puntos de reaparicion

using ETSIDI::SpriteSequence;

class Heroe: public Personaje{
protected:
	float vida;
	float alturamuerte;

	////Puntosreaparicion;
	int numeroRP;
	Vector2D *puntosR[Max_Size];
	////Hitbox 
	enum Estado { Show, Hide };
	Estado estado = Hide;

	////Grafico
	SpriteSequence run, jumpUP, jumpDOWN;

public:
	Heroe();
	virtual ~Heroe();

	//METODOS GET
	int GetVida();

	//METODOS SET
	void SetAlturaMuerte(float am);
	void SetVida( float v);

	//ANIMACIONES
	virtual void Dibuja();
	virtual void Mueve(float t);

	//FUNCIONES
	bool Muerte();
	void ShowHitbox(bool e);
	void PuntoReaparicion();
	bool AgregarPuntosR(Vector2D* p);
	void DestruirContenido();
};
