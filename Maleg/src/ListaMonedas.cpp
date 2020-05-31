#include <iostream>
#include "ListaMonedas.h"

using namespace std;

ListaMonedas::ListaMonedas() {
	numero = 0;//numero inicial de monedas
	for (int i = 0;i < MAX_MON;i++) {
		lista[i] = 0; //todo el puntero esta a NULL
	}
}//constructor

ListaMonedas::~ListaMonedas() {

}//destructor

bool ListaMonedas::agregar(Moneda* m) {
	if (numero < MAX_MON) {
		lista[numero] = m;

		numero++;
	
	}
	else return false;
	

}
void ListaMonedas::destruirContenido() {

}

void ListaMonedas::Dibuja() {
	for (int i = 0;i < numero;i++) {
		lista[i]->Dibuja();//direccion de memoria del elemento(moneda)
	}                       //recorre una a una la lista de monedas que tenemos y las dibuja
}

void ListaMonedas::Mueve(float t) {
	for (int i = 0;i < numero;i++) {
		lista[i]->Mueve(t);
	}
}

Moneda* ListaMonedas::Colision(Personaje* p){
	for (int i = 0; i < numero;i++) {
		if (Interaccion::ColisionMoneda(p, *(lista[i])))
				return lista[i];
			
	}
}
void ListaMonedas::Eliminar(Moneda* e) {//borrar esfera según su dirección de memoria
	for (int i = 0;i < numero;i++) {
		if (lista[i] == e) {
			Eliminar(i);
			return;
		}
	}
}
void ListaMonedas::Eliminar(int index) {//borrar una esfera segun su indice
	if ((index < 0) || (index >= numero)) {//si el indice esta fuera de rango
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index;i < numero;i++) {
		lista[i] = lista[1 + i];
	}
}

