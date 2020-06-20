#include <iostream>
#include "ListaEnemigos.h"
using namespace std;


ListaEnemigos::ListaEnemigos(){

	nume = 0;
	
	for (int i = 0; i < MAX_ENEM; i++) {
		Lista_e[i] = 0;
	}
}

ListaEnemigos::~ListaEnemigos() {


}

bool ListaEnemigos::AgregarE(Enemigo* e) {

	if (nume < MAX_ENEM) {
		Lista_e[nume] = e;
		nume++;
		return true;
	}
	else
		return false;
}


void ListaEnemigos::DestruirContenido() {
	for (int i = 0;i < nume;i++) {
		delete Lista_e[i];
	}
	nume = 0;

}

void ListaEnemigos::Dibuja() {

	for (int i = 0; i < nume; i++) {
			Lista_e[i]->Dibuja();
	}

}

void ListaEnemigos::Mueve(float t) {

	for (int i = 0;i < nume;i++) {
		Lista_e[i]->Mueve(t);
		//lista_e[i]->Bucle();
	}
}

bool ListaEnemigos::Colision(Heroe* p) {
	
	for (int i = 0; i < nume;i++) {
		if (Interaccion::ColisionEnemigo(p, *(Lista_e[i]))) {
			cout << "impacto" << endl;
			p->SetPos(0.0f, 3.0f);
			p->SetVel(0.0f, 0.0f);
			return true;

		}

	}

	return false;
}
void ListaEnemigos::Eliminar(Enemigo* e) {


}

void ListaEnemigos::Eliminar(int index) {


}