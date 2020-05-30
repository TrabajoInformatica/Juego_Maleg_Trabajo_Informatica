#include "ObjetoMovil.h"

void ObjetoMovil::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void  ObjetoMovil::SetAce(float ax,float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}

void ObjetoMovil::SetPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void ObjetoMovil::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

Vector2D ObjetoMovil::GetVel() {
	return velocidad;
}

Vector2D  ObjetoMovil::GetPos() {

	return posicion;
}