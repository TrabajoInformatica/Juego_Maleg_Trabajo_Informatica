#include "ListaPlataformas.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Interaccion.h"
using namespace std;


ListaPlataformas::ListaPlataformas() {
	numerop = 0;
	for (int i = 0;i < MAX_SIZE;i++)
		Listap[i] = 0;
}

ListaPlataformas::~ListaPlataformas() {

}

void ListaPlataformas::DestruirContenido() {
	for (int i = 0;i < numerop;i++) {
		delete Listap[i];
		numerop = 0;
	}
}

Plataforma ListaPlataformas::GetListaPlat(int num){
	return *(Listap[num]);
}

int ListaPlataformas::GetNumPlat(){
	return numerop;
}

void ListaPlataformas::Dibuja() {
	for (int i = 0;i < numerop;i++)
		Listap[i]->Dibuja();
}

bool ListaPlataformas::AgregarP(Plataforma* p) {
	for (int i = 0;i < numerop;i++) {
		if ((Listap[i]) == p)
			return false;
	}
	if (numerop < MAX_SIZE)
		Listap[numerop++] = p;
	else
		return false;
	return true;
}

void ListaPlataformas::LecturaFichero(string Fichero) {
	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, gr = 0;
	float r = 0, v = 0, a = 0;
	int b = 0, i = 1, longitud = 0, pos = 0;
	int opcion = 5;
	string tipo;
	string introduccion = { "X1_Y1_X2_Y2_GROSOR_ROJO_VERDE_AZUL" };
	string comentario;

	fstream archivo;
	archivo.open(Fichero, ios::in);	//Abriendo archivo modo lectura
	if (archivo.fail()) {
		cout << "No se pudo abrir archivo";
		exit(1);
	}
	/*
	while (!archivo.eof()) {//Mientras no acabe archivo.txt
		if ((archivo.get() == '\n'))
			i++;
	}
	archivo.clear();										//Al llegar al final del archivo(eof) en en bucle anterior se anula cualquier operacion
	archivo.seekg(0);										// por lo que se usa .clear() con eso limpias los flags de estado y luego se puede usar el .seekg() que posiciona el cursor de lectura de fichero al inicio
	*/
	while (!archivo.eof()) {
		if (opcion == 1) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> r >> v >> a >> comentario;
			Plataforma* aux = new Plataforma(x1, y1, x2, y2, gr, (unsigned char)r, (unsigned char)v, (unsigned char)a);///////Creacion Plataformas
			AgregarP(aux);
		}
		if (opcion == 2) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> r >> v >> a >> comentario;
			Bloque* aux = new Bloque(x1, y1, x2, y2, gr, (unsigned char)r, (unsigned char)v, (unsigned char)a);	///////Creacion Bloques
			AgregarP(aux);
		}
		archivo >> tipo;
		if (tipo == "Plataforma")									//Con esto detecto si estoy en el espacio plataformas o bloques
			opcion = 1;												//1 Leo una linea y lo guardo en un string
		if (tipo == "Bloque")										//2 Comparo si es Plataforma o bloque y se queda fijado en el estado que sea
			opcion = 2;												// hasta nueva orden 
		if (tipo != "Plataforma" && tipo != "Bloque" && !archivo.eof() && tipo != introduccion) {//Como leo todas las lineas con un string, tengo que retornar el carro al inicio
			longitud = tipo.size();									// de esa linea si no  leo  plataforma o bloque, ya que estoy leyendo datos.
			pos = archivo.tellg();									//hay que indicar tmb que no retorne carro en la ultima linea de coordenadas con !eof sino se 
			pos = pos - longitud;									//se genera un bucle infinito de retorno de carro
			archivo.seekg(pos);
		}
	}
	archivo.close();
}

void ListaPlataformas::Colision(Heroe* pers) {
	for (int i = 0;i < numerop;i++) {
		if (Interaccion::ColisionLat(pers, *(Listap[i]))) {
			pers->SetVel(0.0f, pers->GetVel().y);
			break;
		}
	}
	
	for (int i = 0;i < numerop; i++) {
		if (Interaccion::ColisionSup(pers, *(Listap[i]))) {
			break;
		}
		else
			pers->SetAce(pers->GetAce().x, -9.8f);
	}

	for (int i = 0;i < numerop;i++) {
		if (Interaccion::ColisionInf(pers, *(Listap[i]))) {
			pers->SetVel(pers->GetVel().x, 0.0f);
			break;
		}
	}

} 

void ListaPlataformas::Mueve(float t) {
	for (int i = 0;i < numerop;i++) {
		Listap[i]->Mueve(t);
	}
}