#include "ListaArmas.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Interaccion.h"
using namespace std;


ListaArmas::ListaArmas() {
	numeroA = 0;
	for (int i = 0;i < MAX_SIZE;i++)
		ListaA[i] = 0;
}

ListaArmas::~ListaArmas() {

}

void ListaArmas::DestruirContenido() {
	for (int i = 0;i < numeroA;i++) {
		delete ListaA[i];
		numeroA = 0;
	}
}

Arma ListaArmas::GetLista(int num) {
	return *(ListaA[num]);
}

int ListaArmas::GetNum() {
	return numeroA;
}

void ListaArmas::Dibuja() {
	for (int i = 0;i < numeroA;i++)
		ListaA[i]->Dibuja();
}

bool ListaArmas::AgregarA(Arma* a) {
	for (int i = 0;i < numeroA;i++) {
		if ((ListaA[i]) == a)
			return false;
	}
	if (numeroA < MAX_SIZE)
		ListaA[numeroA++] = a;
	else
		return false;
	return true;
}

void ListaArmas::Mueve(float t) {
	for (int i = 0;i < numeroA;i++) {
		ListaA[i]->Mueve(t);
	}
}