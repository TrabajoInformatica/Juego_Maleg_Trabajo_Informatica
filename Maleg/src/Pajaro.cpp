#include "Pajaro.h"

Pajaro::Pajaro(): sprite("imagenes/Parrot.png",3,3){
}

Pajaro::~Pajaro() {



}
Pajaro::Pajaro(float px, float py): sprite("imagenes/Parrot.png", 3, 3) {

	posicion.x = px;
	posicion.y = py;
	aceleracion.x = 2.0;
	verde = 0;
	azul = 0;
	rojo = 255;
	altura = 0.5f;
	velocidad.x = 1.0f;
	lim_xi = posicion.x - 10.0f;
	//lim_yi = posicion.y + 7.0f;
	lim_xd = posicion.x + 10.0f;
	//lim_yd = posicion.y - 7.0f;

}

void Pajaro::Mueve(float t) {

	ObjetoMovil::Mueve(t);
	Movimiento();
}

void Pajaro::Movimiento() {

	if (posicion.x > lim_xd) {
		posicion.x = lim_xd;
		velocidad.x = -2.5f;
		aceleracion.x = -2.0f;
	}
	else if (posicion.x < lim_xi) {
		posicion.x = lim_xi;
		velocidad.x = 2.5f;
		aceleracion.x = 2.0f;
	}
}

void Pajaro::Dibuja() {

//Dimensiones del sprite
	sprite.setCenter(1, 1);
	sprite.setSize(2, 2);
//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	sprite.loop();
	glPopMatrix();

	//////////Dibuja el Hitbox de pajaro
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

void Pajaro::ShowHitbox(bool e) {
	if (e == true)
		estado = Show;
	else
		estado = Hide;
}
