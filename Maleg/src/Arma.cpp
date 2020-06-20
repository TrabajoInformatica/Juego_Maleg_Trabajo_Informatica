#include "Arma.h"
#include "glut.h"

Arma::Arma() {
	rojo = verde = 255;
	azul = 0;
	radio = 0.5;
}
Arma::Arma(float px, float py, unsigned char r, unsigned char v, unsigned char a) {
	posicion.x = px;
	posicion.y = py;
	rojo = r;
	verde = v;
	azul = a;
}

Arma::~Arma() {

}
void Arma::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}
void Arma::SetRadio(float r) {
	radio = r;
}
float Arma::GetRadio() {
	return radio;
}


