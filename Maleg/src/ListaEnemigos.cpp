#include "ListaEnemigos.h"


ListaEnemigos::ListaEnemigos(){

	num = 0;
	for (int i = 0; i < MAX_ENEM; i++) {
		lista_s[i] = 0;
		lista_p[i] = 0;
		lista_g[i] = 0;
	}

}

ListaEnemigos::~ListaEnemigos() {


}

bool ListaEnemigos::Agregar(Sirena* s) {

	if (num < MAX_SIRENA) {
		lista_s[num] = s;

		num++;

	}
	else return false;
}

bool ListaEnemigos::Agregar(Pajaro* p) {

	if (num < MAX_PAJARO) {
		lista_p[num] = p;

		num++;

	}
	else return false;

}

bool ListaEnemigos::Agregar(Guerreros* g) {

	if (num < MAX_GUERR) {
		lista_g[num] = g;

		num++;

	}
	else return false;
}

void ListaEnemigos::DestruirContenido() {


}

void ListaEnemigos::Dibuja() {

	for (int i = 0;i < num;i++) {
		lista_s[i]->Dibuja();
		lista_p[i]->Dibuja();
		lista_g[i]->Dibuja();
	}

}

void ListaEnemigos::Mueve(float t) {

	for (int i = 0;i < num;i++) {
		lista_s[i]->Mueve(t);
		lista_p[i]->Mueve(t);
		lista_g[i]->Mueve(t);
	}
}

void ListaEnemigos::Eliminar(Enemigo* e) {


}

void ListaEnemigos::Eliminar(int index) {


}