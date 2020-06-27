#include "Nivel2.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

Nivel2::Nivel2() {
	fin = false;
}

Nivel2::~Nivel2() {

}

void Nivel2::DestruirContenido() {
	plataformas2.DestruirContenido();
	armas2.DestruirContenido();
	monedas2.destruirContenido();
	corazones2.DestruirContenido();

}
void Nivel2::Inicializa(Heroe h) {
	heroe2= h;
	/////////////////////////////////////Personaje
	heroe2.SetAlturaMuerte(-15.0);
	heroe2.SetPos(0.0f, 0.0f);
	heroe2.SetVel(0.0f, 0.0f);
	////////////////////////////////////Plataformas
	LecturaFichero(Fichero);
	Puerta* puer = new Puerta(200.0f, 30.0f, 204.0f, 30.0f, -5.0f, 255, 0, 0);
	puerta2.AgregarP(puer);
	///////////////////////////////////Enemigos

	Ara�a* ax0 = new Ara�a(30.0f, 22.8f);
	enemigos2.AgregarE(ax0);
	Ara�a* ax1 = new Ara�a(54.5f, 28.8f);
	enemigos2.AgregarE(ax1);
	Ara�a* ax2 = new Ara�a(97.5f, 27.8f);
	enemigos2.AgregarE(ax2);

	Murcielago* mx0 = new Murcielago(16.0f, 25.0f);
	enemigos2.AgregarE(mx0);
	Murcielago* mx1 = new Murcielago(40.0f, 35.0f);
	enemigos2.AgregarE(mx1);
	Murcielago* mx2 = new Murcielago(82.0f, 47.0f);
	enemigos2.AgregarE(mx2);
	Murcielago* mx3 = new Murcielago(110.0f, 40.0f);
	enemigos2.AgregarE(mx3);
	Murcielago* mx4 = new Murcielago(167.0f, 39.5f);
	enemigos2.AgregarE(mx4);

	Guerreros* gx0 = new Guerreros(116.5f, 29.0f, 4.5f, 1.5f);
	enemigos2.AgregarE(gx0);
	Guerreros* gx1 = new Guerreros(164.0f, 32.0f, 3.0f, -2.0f);
	enemigos2.AgregarE(gx1);
}

void Nivel2::Dibuja() {
	gluLookAt(heroe2.GetPos().x, heroe2.GetPos().y + 1, 3,  // posicion del ojo						//NUNCA MODIFICAR LA Z	No hace fala
		heroe2.GetPos().x, heroe2.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)			//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);
	/////////////////////////////////////Personaje
	//cout << "estoy dibujado nivel 2" << endl;


	// Background
	glEnable(GL_TEXTURE_2D);
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/doomforest.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-40, 10, 0.6);
	glTexCoord2d(1, 1); glVertex3f(40, 10, 0.6);
	glTexCoord2d(1, 0); glVertex3f(40, 50, 0.6);
	glTexCoord2d(0, 0); glVertex3f(-40, 50, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(40, 10, 0.6);
	glTexCoord2d(1, 1); glVertex3f(120, 10, 0.6);
	glTexCoord2d(1, 0); glVertex3f(120, 50, 0.6);
	glTexCoord2d(0, 0); glVertex3f(40, 50, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(120, 10, 0.6);
	glTexCoord2d(1, 1); glVertex3f(200, 10, 0.6);
	glTexCoord2d(1, 0); glVertex3f(200, 50, 0.6);
	glTexCoord2d(0, 0); glVertex3f(120, 50, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(200, 10, 0.6);
	glTexCoord2d(1, 1); glVertex3f(280, 10, 0.6);
	glTexCoord2d(1, 0); glVertex3f(280, 50, 0.6);
	glTexCoord2d(0, 0); glVertex3f(200, 50, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bottom2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-40, 12, 0.5);
	glTexCoord2d(1, 1); glVertex3f(260, 12, 0.5);
	glTexCoord2d(1, 0); glVertex3f(260, -40, 0.5);
	glTexCoord2d(0, 0); glVertex3f(-40, -40, 0.5);
	glEnd();
	//------------------------------------------------------------------------------------------
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


////////////////////////////////////Plataformas
	heroe2.Dibuja();
	plataformas2.Dibuja();
	monedas2.Dibuja();
	armas2.Dibuja();
	corazones2.Dibuja();
	puerta2.DibujaP();

	//cout << "X" << heroe2.GetPos().x << endl;
	//cout << "Y" << heroe2.GetPos().y << endl;
	///////////////////////////////////Enemigos
	enemigos2.Dibuja();
}
void Nivel2::Mueve() {
	///////Movimiento
	monedas2.Mueve(0.025f);
	heroe2.Mueve(0.1f);
	enemigos2.Mueve(0.25f);
	plataformas2.Mueve(0.025f);
	armas2.Mueve(0.05f);
	corazones2.Mueve(0.025f);

	//////Colisiones
	plataformas2.Colision(&heroe2);
	monedas2.Colision(&heroe2);	
	//enemigos2.Colision(&heroe2);
	corazones2.Colision(&heroe2);

	if (puerta2.Colision(&heroe2) == true) {
		cout << "puerta2" << endl;
		fin = true;
	}
	else
		fin = false;

	for (int i = 0;i < enemigos2.GetNumeroE();i++) {
		for (int j = 0;j < armas2.GetNum();j++) {
			if (Interaccion::ColisionEnemigo(armas2.GetLista(j), enemigos2.GetListaEnem(i))) {
				armas2.Eliminar(j);
				enemigos2.Eliminar(i);
			}
		}
	}
}

Heroe Nivel2::GetHeroe() {
	heroe2.DestruirContenido();
	return heroe2;
}

bool Nivel2::FinNivel2() {
	if (fin == true) {
		return true;
		cout << "ha pasado al nivel 3" << endl;
	}
	else
		return false;
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
		heroe2.DestruirContenido();
		return true;
	}
	else
		return false;
}

void Nivel2::LecturaFichero(string Fichero) {
	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, gr = 0, pf=0;
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
		if (opcion == 7) {
			archivo >> x1 >> y1 >> pf >> r >> vy >> comentario;
			VidaExtra* aux = new VidaExtra(x1, y1, pf, r, vy);///////Creacion Monedas
			corazones2.AgregarC(aux);
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
		if (tipo == "VidasExtra")
			opcion = 7;
		if (tipo != "Plataforma" && tipo != "Plataforma_movil" && !archivo.eof() && tipo != introduccion && tipo != "Monedas" &&
			tipo != "Enemigos" && tipo != "Sirena" && tipo != "Pajaro" && tipo != "PuntosReaparicion" && tipo != "Heroe" && tipo != "VidasExtra") {//Como leo todas las lineas con un string, tengo que retornar el carro al inicio
			longitud = tipo.size();									// de esa linea si no  leo  plataforma o bloque, ya que estoy leyendo datos.
			pos = archivo.tellg();									//hay que indicar tmb que no retorne carro en la ultima linea de coordenadas con !eof sino se 
			pos = pos - longitud;									//se genera un bucle infinito de retorno de carro
			archivo.seekg(pos);
		}
		suma++;
	}
	archivo.close();
}