#include "Pajaro.h"

Pajaro::Pajaro(){
	verde = 255;
	azul = 0;
	rojo = 0;
	altura = 0.5f;
}

Pajaro::~Pajaro() {


}
Pajaro::Pajaro(float px, float py) {

	verde = 255;
	azul = 0;
	rojo = 0;
	altura = 0.5f;
	posicion.x = px;
	posicion.y = py;

}

void Pajaro::Mueve() {

}