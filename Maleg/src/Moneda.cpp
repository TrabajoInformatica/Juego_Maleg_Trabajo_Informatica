#include "Moneda.h"
#include "glut.h"

Moneda::Moneda() {
	rojo = verde = 255;
	azul = 0;
	radio = 0.5;
	radio_max = 0.5f;
	radio_min = 0.35f;
	pulso = 0.5f;
}
Moneda::Moneda(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

Moneda::~Moneda() {

}
void Moneda::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}
void Moneda::SetRadio(float r) {
	radio = r;
}
float Moneda::GetRadio() {
	return radio;
}
void Moneda::SetPos(float posx, float posy) {
	posicion.x = posx;
	posicion.y = posy;
}
Vector2D Moneda::GetPos() {
	return posicion;
}

void Moneda::Dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
void Moneda::Mueve(float t) {

	if (radio > radio_max)
		pulso = -pulso;

	if (radio < radio_min)
		pulso = -pulso;

	radio += pulso * t;
}
