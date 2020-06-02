#include <iostream>
#include "ListaEnemigos.h"
using namespace std;


ListaEnemigos::ListaEnemigos(){
	numeroe = 0;
	for (int i = 0;i < MAX_SIZE;i++) {
		Listae[i] = 0;
	}
}

ListaEnemigos::~ListaEnemigos() {

}

bool ListaEnemigos::Agregar(Enemigo* e) {
	for (int i = 0;i < numeroe;i++) {
		if ((Listae[i]) == e)
			return false;
	}
	if (numeroe < MAX_SIZE)
		Listae[numeroe++] = e;
	else
		return false;
	return true;
}

void ListaEnemigos::DestruirEnemigos() {
	for (int i = 0;i < numeroe;i++) {
		delete Listae[i];
		numeroe = 0;
	}
}

void ListaEnemigos::Dibuja() {
	for (int i = 0;i < numeroe;i++)
		Listae[i]->Dibuja();
}

void ListaEnemigos::Mueve(float t) {
	for (int i = 0;i < numeroe;i++)
		Listae[i]->Mueve(t);
}

void ListaEnemigos::Colision(Heroe *p) {
	for (int i = 0;i < numeroe;i++) {
		if (Interaccion::ColisionEnemigo(p, *(Listae[i]))) {
			p->SetPos(0.0f, 0.0f + p->GetAltura());
			p->SetVel(0.0f, 0.0f);
			break;
		}
	}
}
