#include "Nivel1.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

Nivel1::Nivel1() {


}

Nivel1::~Nivel1() {

}

int Nivel1::getVidaHeroe() {
	return vida;
}
void Nivel1::SetVidaHeroe(int vidas) {
	vida = vidas;

}


void Nivel1::Inicializa() {
	/////////////////////////////////////Personaje
	
	heroe.SetAlturaMuerte(-15.0f);
	heroe.SetPos(134.0f,14.0f);
	heroe.SetVel(0.0f, 0.0f);
	
	////////////////////////////////////Inicializa Plataformas, Monedas , Enemigos
	LecturaFichero(Fichero);

}

void Nivel1::Dibuja() {
	// Vista
	gluLookAt(heroe.GetPos().x,heroe.GetPos().y+ 1, 3,  // posicion del ojo						//NUNCA MODIFICAR LA Z	No hace fala
		heroe.GetPos().x, heroe.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)			//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// Enemigos
	enemigos.Dibuja();

	// Heroe
	heroe.SetVida(vida);
	for (int i = 0; i < plataformas.GetNumPlat(); i++) {
		if (Interaccion::ColisionSup(&heroe, plataformas.GetListaPlat(i))&&heroe.GetVel().y==0)
			heroe.AnimationRun();
		else if (heroe.GetVel().y > 0.0f)
			heroe.AnimationJumpUp();
		else if (heroe.GetVel().y < 0.0f)
			heroe.AnimationJumpDown();
	}

    //Plataformas, Monedas y otros.
	plataformas.Dibuja();
	monedas.Dibuja();
	marcador.Dibuja(&heroe);
}

void Nivel1::Mueve() {
	// Enemigos
	enemigos.Mueve(0.025f);	

	// Heroe
	heroe.Mueve(0.09f);
	// Plataforma, Monedas y otros.
	plataformas.Mueve(0.025f);
	plataformas.Colision(&heroe);

	monedas.Mueve(0.025f);
	Moneda* aux = monedas.Colision(&heroe);
	if (aux != 0)//si alguna esfera ha chocado con el hombre
		monedas.Eliminar(aux);

	/////////Provisional
	enemigos.Colision(&heroe);
}

void Nivel1::Tecla(unsigned char key) {
	if (key == 'w') {
		for (int i = 0; i < plataformas.GetNumPlat(); i++) {
			if (Interaccion::ColisionSup(&heroe, plataformas.GetListaPlat(i))) {
				heroe.SetVel(heroe.GetVel().x, 10.0f);
			}
			else {
				heroe.SetVel(heroe.GetVel().x, heroe.GetVel().y);
			}
		}
	}
	if (key == 'a')
		heroe.SetVel(-3.0f, heroe.GetVel().y);
	if (key == 'd')
		heroe.SetVel(3.0f, heroe.GetVel().y);
}

void Nivel1::TeclaUp(unsigned char key) {
	if (key == 'a')
		heroe.SetVel(0.0f, heroe.GetVel().y);
	if (key == 'd')
		heroe.SetVel(0.0f, heroe.GetVel().y);
}

bool Nivel1::MuerteHeroe() {
	if (heroe.Muerte()) {
		cout << "Muerto" << endl;
		return true;
	}else
		return false;
}

void Nivel1::LecturaFichero(string Fichero) {
	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, gr = 0;
	float r = 0, v = 0, a = 0, vx = 0, vy = 0;
	int b = 0, i = 1, longitud = 0, pos = 0, p;
	int opcion = 0;
	string tipo;
	string introduccion = { "X1_Y1_X2_Y2_GROSOR_ROJO_VERDE_AZUL" };
	string comentario;
	fstream archivo;
	archivo.open(Fichero, ios::in);	//Abriendo archivo modo lectura
	if (archivo.fail()) {
		cout << "No se pudo abrir archivo";
		exit(1);
	}
	while (!archivo.eof()) {
		if (opcion == 1) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> r >> v >> a >> comentario;
			Plataforma* aux = new Plataforma(x1, y1, x2, y2, gr, (unsigned char)r, (unsigned char)v, (unsigned char)a);///////Creacion Plataformas
			plataformas.AgregarP(aux);
		}
		if (opcion == 2) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> p >> vx >> vy >> r >> v >> a >> comentario;
			PlataformaMovil* aux = new PlataformaMovil(x1, y1, x2, y2, gr, p, vx, vy, (unsigned char)r, (unsigned char)v, (unsigned char)a);	///////Creacion Plataforma Movil
			plataformas.AgregarP(aux);
		}
		if (opcion == 3) {
			archivo >> x1 >> y1 >> gr >> r >> v >> a >> comentario;
			Moneda* aux = new Moneda(x1, y1, gr, r, v, a);///////Creacion Monedas
			monedas.AgregarM(aux);
		}
		if (opcion == 4) {
			archivo >> x1 >> y1 >> comentario;
			Sirena* aux = new Sirena(x1, y1);
			enemigos.AgregarE(aux);
		}
		if (opcion == 5) {
			archivo >> x1 >> y1 >> comentario;
			Pajaro* aux = new Pajaro(x1, y1);
			enemigos.AgregarE(aux);
		}
		archivo >> tipo;
		if (tipo == "Plataforma")
			opcion = 1;
		if (tipo == "Plataforma_movil")
			opcion = 2;
		if (tipo == "Monedas")
			opcion = 3;
		if (tipo == "Enemigos")
			opcion = 300;
		if (tipo == "Sirena")
			opcion = 4;
		if (tipo == "Pajaro")
			opcion = 5;
		if (tipo != "Plataforma" && tipo != "Plataforma_movil" && !archivo.eof() && tipo != introduccion && tipo != "Monedas" &&tipo!="Enemigos" &&tipo !="Sirena" && tipo !="Pajaro") {//Como leo todas las lineas con un string, tengo que retornar el carro al inicio
			longitud = tipo.size();									// de esa linea si no  leo  plataforma o bloque, ya que estoy leyendo datos.
			pos = archivo.tellg();									//hay que indicar tmb que no retorne carro en la ultima linea de coordenadas con !eof sino se 
			pos = pos - longitud;									//se genera un bucle infinito de retorno de carro
			archivo.seekg(pos);
		}
	}
	archivo.close();
}


