#include "Enemigo.h"

Enemigo::Enemigo()
{
	verde = 255;
	rojo = 100;
	azul = 100;
	vida = 1;
}

Enemigo::~Enemigo()
{

}
float Enemigo::GetRadio() {
	return altura;
}

/*void Enemigo::SetVida(int v) {
	vida = v;
}

int Enemigo::GetVida() {
	
	cout << "vida:" << vida << endl;
	return vida;
}*/

bool Enemigo::Muerte() {

	if (vida == 0) {
		return true;
	}
	else
		return false;
}

