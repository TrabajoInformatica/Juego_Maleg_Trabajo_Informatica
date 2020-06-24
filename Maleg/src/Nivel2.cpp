#include "Nivel2.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

Nivel2::Nivel2() {
	fin = false;
}

Nivel2::~Nivel2() {
	plataformas2.DestruirContenido();
}

void Nivel2::Inicializa(int vidas) {
	LecturaFichero(Fichero);
	/////////////////////////////////////Personaje
	heroe2.SetAlturaMuerte(-10.0);
	heroe2.SetVida(vidas); //si se hace con el mismo heroe no 
	heroe2.SetPos(0.0f, 0.0f);
	heroe2.SetVel(0.0f, 0.0f);
	vidaextra2.SetPos(75.9, 41.5f);
	////////////////////////////////////Plataformas


	///////////////////////////////////Enemigos

	Araña* ax0 = new Araña(30.0f, 22.8f);
	enemigos2.AgregarE(ax0);
	Araña* ax1 = new Araña(54.5f, 28.8f);
	enemigos2.AgregarE(ax1);
	Araña* ax2 = new Araña(97.5f, 27.8f);
	enemigos2.AgregarE(ax2);
}

void Nivel2::Dibuja() {
	gluLookAt(heroe2.GetPos().x, heroe2.GetPos().y + 1, 3,  // posicion del ojo						//NUNCA MODIFICAR LA Z	No hace fala
		heroe2.GetPos().x, heroe2.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)			//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);
	/////////////////////////////////////Personaje
	cout << "estoy dibujado nivel 2" << endl;
////////////////////////////////////Plataformas
	heroe2.Dibuja();
	plataformas2.Dibuja();
	monedas2.Dibuja();
	armas2.Dibuja();

	vidaextra2.Dibuja();

	cout << "X" << heroe2.GetPos().x << endl;
	cout << "Y" << heroe2.GetPos().y << endl;
	///////////////////////////////////Enemigos
	enemigos2.Dibuja();
}
void Nivel2::Mueve() {
	///////Movimiento
	monedas2.Mueve(0.025f);
	heroe2.Mueve(0.1f);
	enemigos2.Mueve(0.25f);
	plataformas2.Mueve(0.025f);
	armas2.Mueve(0.025f);
	vidaextra2.Mueve(0.025f,41.5f);

	//////Colisiones
	plataformas2.Colision(&heroe2);
	monedas2.Colision(&heroe2);	
	enemigos2.Colision(&heroe2);

	for (int i = 0;i < enemigos2.GetNumeroE();i++) {
		for (int j = 0;j < armas2.GetNum();j++) {
			if (Interaccion::ColisionEnemigo(armas2.GetLista(j), enemigos2.GetListaEnem(i))) {
				armas2.Eliminar(j);
				enemigos2.Eliminar(i);
			}
		}
	}
}

void Nivel2::Tecla(unsigned char key) {
	if (key == 'w') {
		for (int i = 0; i < plataformas2.GetNumPlat(); i++) {
			if (Interaccion::ColisionSup(&heroe2, plataformas2.GetListaPlat(i))) {
				heroe2.SetVel(heroe2.GetVel().x, 10.0f);
			}
			else {
				heroe2.SetVel(heroe2.GetVel().x, heroe2.GetVel().y);
			}
		}
	}
	if (key == 'a')
		heroe2.SetVel(-3.0f, heroe2.GetVel().y);

	if (key == 'd')
		heroe2.SetVel(3.0f, heroe2.GetVel().y);

	////////Hitbox
	if (key == '1' && estado == ShowHitbox) {
		estado = HideHitbox;
	}
	else if (key == '1' && estado == HideHitbox) {
		estado = ShowHitbox;
	}
	if (estado == ShowHitbox) {
		heroe2.ShowHitbox(true);
		enemigos2.ShowHitbox(true);
	}
	else {
		heroe2.ShowHitbox(false);
		enemigos2.ShowHitbox(false);
	}

	if (key == ' ') {
		if (heroe2.ValidarDisparo()) {
			ETSIDI::play("sonidos/DisparoFlecha.mp3");
			if (heroe2.Disparo()) {
				Lanza* aux = new Lanza(heroe2.GetPos().x + heroe2.GetAltura(), heroe2.GetPos().y, 10);
				armas2.AgregarA(aux);
				heroe2.SumarMonedas(false);
			}
			else if (!heroe2.Disparo()) {
				Lanza* aux = new Lanza(heroe2.GetPos().x - heroe2.GetAltura(), heroe2.GetPos().y, -10);
				armas2.AgregarA(aux);
				heroe2.SumarMonedas(false);
			}
		}
	}
}
void Nivel2::TeclaUp(unsigned char key) {
	if (key == 'a')
		heroe2.SetVel(0.0f, heroe2.GetVel().y);
	if (key == 'd')
		heroe2.SetVel(0.0f, heroe2.GetVel().y);
}
bool Nivel2::MuerteHeroe() {
	if (heroe2.Muerte()) {
		cout << "Muerto" << endl;
		return true;
	}
	else
		return false;
}

void Nivel2::LecturaFichero(string Fichero) {
	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, gr = 0;
	float r = 0, v = 0, a = 0, vx = 0, vy = 0;
	int b = 0, i = 1, longitud = 0, pos = 0, p, suma = 0;
	int opcion = 999;
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
		cout << suma << endl;
		if (opcion == 1) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> r >> v >> a >> comentario;
			Plataforma* aux = new Plataforma(x1, y1, x2, y2, gr, (unsigned char)r, (unsigned char)v, (unsigned char)a);///////Creacion Plataformas
			plataformas2.AgregarP(aux);
		}
		if (opcion == 2) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> p >> vx >> vy >> r >> v >> a >> comentario;
			PlataformaMovil* aux = new PlataformaMovil(x1, y1, x2, y2, gr, p, vx, vy, (unsigned char)r, (unsigned char)v, (unsigned char)a);	///////Creacion Plataforma Movil
			plataformas2.AgregarP(aux);
		}
		if (opcion == 3) {
			archivo >> x1 >> y1 >> gr >> r >> v >> a >> comentario;
			Moneda* aux = new Moneda(x1, y1, gr, r, v, a);///////Creacion Monedas
			monedas2.AgregarM(aux);
		}
		if (opcion == 4) {
			archivo >> x1 >> y1 >> comentario;
			Sirena* aux = new Sirena(x1, y1);
			enemigos2.AgregarE(aux);
		}
		if (opcion == 5) {
			archivo >> x1 >> y1 >> comentario;
			Pajaro* aux = new Pajaro(x1, y1);
			enemigos2.AgregarE(aux);
		}
		if (opcion == 6) {
			archivo >> x1 >> y1 >> comentario;
			Vector2D* aux = new Vector2D(x1, y1);
			heroe2.AgregarPuntosR(aux);
		}
		archivo >> tipo;
		if (tipo == "Plataforma")
			opcion = 1;
		if (tipo == "Plataforma_movil")
			opcion = 2;
		if (tipo == "Monedas")
			opcion = 3;
		if (tipo == "Enemigos" || tipo == "Heroe")
			opcion = 300;
		if (tipo == "Sirena")
			opcion = 4;
		if (tipo == "Pajaro")
			opcion = 5;
		if (tipo == "PuntosReaparicion")
			opcion = 6;
		if (tipo != "Plataforma" && tipo != "Plataforma_movil" && !archivo.eof() && tipo != introduccion && tipo != "Monedas" &&
			tipo != "Enemigos" && tipo != "Sirena" && tipo != "Pajaro" && tipo != "PuntosReaparicion" && tipo != "Heroe") {//Como leo todas las lineas con un string, tengo que retornar el carro al inicio
			longitud = tipo.size();									// de esa linea si no  leo  plataforma o bloque, ya que estoy leyendo datos.
			pos = archivo.tellg();									//hay que indicar tmb que no retorne carro en la ultima linea de coordenadas con !eof sino se 
			pos = pos - longitud;									//se genera un bucle infinito de retorno de carro
			archivo.seekg(pos);
		}
		suma++;
	}
	archivo.close();
}