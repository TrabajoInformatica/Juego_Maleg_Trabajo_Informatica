#include "Ara�a.h"

Ara�a::Ara�a(): spyder("imagenes/ara�a(x).png", 3, 1){
}

Ara�a::Ara�a(float px, float py): spyder("imagenes/ara�a(x).png", 3, 1){
	
	posicion.x = px;
	posicion.y = py;
	aceleracion.x = 10.0f;
	verde = 0;
	azul = 0;
	rojo = 255;
	altura = 0.4f;
	velocidad.x = 10.0f;
	lim_xi = posicion.x - 3.0f;
	lim_ya = posicion.y + 0.75f;
	lim_xd = posicion.x + 3.0f;
	lim_yb = posicion.y - 0.75f;
}

Ara�a::Ara�a(float px, float py, float limitex ,float limitey) : spyder("imagenes/ara�a(x).png", 3, 1) {
	posicion.x = px;
	posicion.y = py;
	aceleracion.x = 10.0f;
	verde = 0;
	azul = 0;
	rojo = 255;
	altura = 0.4f;
	velocidad.x = 10.0f;
	lim_xi = posicion.x - limitex;
	lim_ya = posicion.y + limitey;
	lim_xd = posicion.x + limitex;
	lim_yb = posicion.y - limitey;

}

Ara�a::~Ara�a() {

}

void Ara�a::Mueve(float t) {

	ObjetoMovil::Mueve(t);
	Movimiento();
}

void Ara�a::Movimiento() {
	if (posicion.x > lim_xd) {
		posicion.x = lim_xd;
		velocidad.y = 5.0f;
		aceleracion.y = 0.5f;
	}
		if (posicion.y > lim_ya) {
			posicion.y = lim_ya;
			velocidad.x = -5.0f;
			aceleracion.x = -0.5f;
			velocidad.y = 0;
			aceleracion.y = 0;

		}
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.y = -5.0f;
		aceleracion.y = -0.5f;
		velocidad.x = 0;
		aceleracion.x = 0;
		}
	else if (posicion.y < lim_yb) {
		posicion.y = lim_yb;
		velocidad.x = 5.0f;
		aceleracion.x = 0.5f;
		velocidad.y = 0;
		aceleracion.y = 0;
		}
}

void Ara�a::Dibuja() {
	//Dimensiones del sprite
	spyder.setCenter(1, 1);
	spyder.setSize(2, 2);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (velocidad.y > 0) { spyder.setAngle(-90.0f); spyder.flip(false, true); }
	else if (velocidad.x > 0.01) { spyder.setAngle(0.0f); spyder.flip(false, true); }
	else if (velocidad.x < 0.01) { spyder.setAngle(0.0f); spyder.flip(true, false); }
	if (velocidad.y < 0) { spyder.setAngle(90.0f); spyder.flip(false, true); }
	spyder.draw();
	spyder.loop();
	glPopMatrix(); 
	//Hitbox
	if (estado == Show) {
		glPushMatrix();
		glColor3ub(rojo, verde, azul);
		glTranslatef(posicion.x, posicion.y, 0);
		glColor3f(rojo, verde, azul);
		glutWireSphere(altura, 10, 10);
		glTranslatef(-posicion.x, -posicion.y, 0);
		glPopMatrix();
	}
}