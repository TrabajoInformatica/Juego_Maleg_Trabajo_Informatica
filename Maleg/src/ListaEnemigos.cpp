#include <iostream>
#include "ListaEnemigos.h"
using namespace std;


ListaEnemigos::ListaEnemigos(){

	numg = 0;
	nums = 0;
	nump = 0;
	for (int i = 0; i < MAX_ENEM; i++) {
		lista_s[i] = 0;
		lista_p[i] = 0;
		lista_g[i] = 0;
	}

}

ListaEnemigos::~ListaEnemigos() {


}

bool ListaEnemigos::AgregarSire(Sirena* s) {

	if (nums < MAX_SIRENA) {
		lista_s[nums] = s;

		nums++;
	}
	else return false;
}

bool ListaEnemigos::AgregarPaja(Pajaro* p) {

	if (nump < MAX_PAJARO) {
		lista_p[nump] = p;

		nump++;

	}
	else return false;

}

bool ListaEnemigos::AgregarGue(Guerreros* g) {

	if (numg < MAX_GUERR) {
		lista_g[numg] = g;

		numg++;

	}
	else return false;
}

void ListaEnemigos::DestruirContenido() {


}

void ListaEnemigos::Dibuja() {

	for (int i = 0;i < nums;i++) {
		
		lista_s[i]->Dibuja();
	}
		for (int i = 0;i < nump;i++) {
		lista_p[i]->Dibuja();}
		for (int i = 0;i < numg;i++) {
		lista_g[i]->Dibuja();}
	

}

void ListaEnemigos::Mueve(float t) {

	for (int i = 0;i < nums;i++) {
		lista_s[i]->Mueve(t);
		lista_s[i]->Salto();
	}
	for (int i = 0;i < nump;i++) {
		lista_p[i]->Mueve(t);
	}
	for (int i = 0;i < numg;i++) {
		lista_g[i]->Mueve(t);
	}
}

Enemigo* ListaEnemigos::Colision(Personaje* p) {
	for (int i = 0; i < nums;i++) {
		if (Interaccion::ColisionEnemigo(p, *(lista_s[i]))) {
			cout << "impactosirena"<<endl;
			return lista_s[i];
		}

	}
	for (int i = 0; i < nump;i++) {
		if (Interaccion::ColisionEnemigo(p, *(lista_p[i]))) {
			cout << "impactopajaro"<<endl;
			return lista_p[i];
		}

	}
}
void ListaEnemigos::Eliminar(Enemigo* e) {


}

void ListaEnemigos::Eliminar(int index) {


}