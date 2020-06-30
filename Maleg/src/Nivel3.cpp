#include "Nivel3.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

Nivel3::Nivel3() {
	fin = false;

}

Nivel3::~Nivel3() {

}
void Nivel3::DestruirContenido() {
	plataformas3.DestruirContenido();
	armas3.DestruirContenido();
	monedas3.destruirContenido();
	corazones3.DestruirContenido();
	puerta3.DestruirContenido();
	puertaextra.DestruirContenido();
}
Heroe Nivel3::GetHeroe() {
	heroe3.DestruirContenido();
	return heroe3;
}

void Nivel3::Inicializa(Heroe h) {
	heroe3 = h;
	/////////////////////////////////////Personaje
	heroe3.SetAlturaMuerte(-15.0f);
	heroe3.SetPos(0.0f, 0.0f);
	heroe3.SetVel(0.0f, 0.0f);
	
	Puerta* puerfin = new Puerta(232.2f, 12.0f, 235.0f, 12.0f, -5.0f, 255, 0, 0);
	puerta3.AgregarP(puerfin);
	Puerta* puerfin2 = new Puerta(108.2f, 100.0f, 110.0f, 100.0f, -5.0f, 255, 0, 0);
	puerta3.AgregarP(puerfin2);
	Puerta* puerex = new Puerta(88.0f, 30.0f, 91.0f, 30.0f, -5.0f, 255, 0, 0);
	puertaextra.AgregarP(puerex);
	

	////////////////////////////////////Inicializa Plataformas, Monedas , Enemigos
	LecturaFichero(Fichero);
	cout << "Nivel333333333333" << endl;

	Ara�a* ax0 = new Ara�a(113.0f, 31.75f,3.5f,0.75f);
	enemigos3.AgregarE(ax0);
	Ara�a* ax1 = new Ara�a(120.5f, 24.75f, 3.0f, 0.75f);
	enemigos3.AgregarE(ax1);
	Ara�a* ax2 = new Ara�a(131.0f, 25.75f, 4.5f, 0.75f);
	enemigos3.AgregarE(ax2);
	Ara�a* ax3 = new Ara�a(47.5f, 2.75f, 3.0f, 0.75f);
	enemigos3.AgregarE(ax3);
	Ara�a* ax4 = new Ara�a(64.0f,-1.25f, 6.5f, 0.75f);
	enemigos3.AgregarE(ax4);

	Murcielago* mx0 = new Murcielago(96.0f, 39.0f);
	enemigos3.AgregarE(mx0);

	Guerreros* gx0 = new Guerreros(132.5f, 16.0f, 9.5f, 3.0f);
	enemigos3.AgregarE(gx0);
	Guerreros* gx1 = new Guerreros(132.5f, 16.0f, 9.5f, -2.0f);
	enemigos3.AgregarE(gx1);
	Guerreros* gx2 = new Guerreros(133.0f, 8.5f, 10.0f, 0.5f);
	enemigos3.AgregarE(gx2);
	Guerreros* gx3 = new Guerreros(133.0f, 8.5f, 10.0f, 3.5f);
	enemigos3.AgregarE(gx3);
	Guerreros* gx4 = new Guerreros(170.0f, 10.0f, 7.0f, -1.5f);
	enemigos3.AgregarE(gx4);
	Guerreros* gx5 = new Guerreros(170.0f, 10.0f, 7.0f, 1.5f);
	enemigos3.AgregarE(gx5);
}

void Nivel3::Dibuja() {
	// Vista
	gluLookAt(heroe3.GetPos().x, heroe3.GetPos().y + 1, 3,  // posicion del ojo						//NUNCA MODIFICAR LA Z	No hace fala
		heroe3.GetPos().x, heroe3.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)			//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// Enemigos
	enemigos3.Dibuja();

	// Heroe
	heroe3.Dibuja();

	//Plataformas, Monedas y otros.
	plataformas3.Dibuja();
	monedas3.Dibuja();
	armas3.Dibuja();
	corazones3.Dibuja();

	puerta3.DibujaP();
	puertaextra.DibujaP();
	
	//cout << "X" << heroe3.GetPos().x << endl;
	//cout << "Y" << heroe3.GetPos().y << endl;
}

void Nivel3::Mueve() {
	// Enemigos
	enemigos3.Mueve(0.25f);
	monedas3.Mueve(0.025f);
	armas3.Mueve(0.025f);
	plataformas3.Mueve(0.025f);
	corazones3.Mueve(0.025f);
	// Heroe
	heroe3.Mueve(0.1f);

	// Plataforma, Monedas y otros.
	plataformas3.Colision(&heroe3);
	monedas3.Colision(&heroe3);
	//enemigos3.Colision(&heroe3);
	corazones3.Colision(&heroe3);

	/////////Provisional
	if (puerta3.Colision(&heroe3) == true) {
		cout << "puerta3" << endl;
		fin = true;
	}
	else
		fin = false;
	if (puertaextra.Colision(&heroe3) == true) {
		cout << "puertaespecial" << endl;
		//	fin = true;
		heroe3.SetPos(97.5f, 101.0f);
	}

	

	for (int i = 0;i < enemigos3.GetNumeroE();i++) {
		for (int j = 0;j < armas3.GetNum();j++) {
			if (Interaccion::ColisionEnemigo(armas3.GetLista(j), enemigos3.GetListaEnem(i))) {
				armas3.Eliminar(j);
				enemigos3.Eliminar(i);
			}
		}
	}
}

bool Nivel3::FinNivel3() {
	if (fin == true) {
		return true;
		cout << "ha pasado" << endl;
	}
	else
		return false;
}

void Nivel3::Tecla(unsigned char key) {
	if (key == 'w') {
		for (int i = 0; i < plataformas3.GetNumPlat(); i++) {
			if (Interaccion::ColisionSup(&heroe3, plataformas3.GetListaPlat(i))) {
				heroe3.SetVel(heroe3.GetVel().x, 10.0f);
			}
			else {
				heroe3.SetVel(heroe3.GetVel().x, heroe3.GetVel().y);
			}
		}
	}
	if (key == 'a')
		heroe3.SetVel(-3.0f, heroe3.GetVel().y);
	if (key == 'd')
		heroe3.SetVel(3.0f, heroe3.GetVel().y);

	////////Hitbox
	if (key == '1' && estado == ShowHitbox) {
		estado = HideHitbox;
	}
	else if (key == '1' && estado == HideHitbox) {
		estado = ShowHitbox;
	}
	if (estado == ShowHitbox) {
		heroe3.ShowHitbox(true);
		enemigos3.ShowHitbox(true);
	}
	else {
		heroe3.ShowHitbox(false);
		enemigos3.ShowHitbox(false);
	}

	if (key == ' ') {
		if (heroe3.ValidarDisparo()) {
			ETSIDI::play("sonidos/DisparoFlecha.mp3");
			if (heroe3.Disparo()) {
				Lanza* aux = new Lanza(heroe3.GetPos().x + heroe3.GetAltura(), heroe3.GetPos().y, 10);
				armas3.AgregarA(aux);
				heroe3.SumarMonedas(false);
			}
			else if (!heroe3.Disparo()) {
				Lanza* aux = new Lanza(heroe3.GetPos().x - heroe3.GetAltura(), heroe3.GetPos().y, -10);
				armas3.AgregarA(aux);
				heroe3.SumarMonedas(false);
			}
		}
	}
}

void Nivel3::TeclaUp(unsigned char key) {
	if (key == 'a')
		heroe3.SetVel(0.0f, heroe3.GetVel().y);
	if (key == 'd')
		heroe3.SetVel(0.0f, heroe3.GetVel().y);
}

bool Nivel3::MuerteHeroe() {
	if (heroe3.Muerte()) {
		cout << "Destruir lanzas 3" << endl;
		heroe3.DestruirContenido();
		return true;
	}
	else
		return false;
}

void Nivel3::LecturaFichero(string Fichero) {
	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, gr = 0, pf = 0;
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
			plataformas3.AgregarP(aux);
		}
		if (opcion == 2) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> p >> vx >> vy >> r >> v >> a >> comentario;
			PlataformaMovil* aux = new PlataformaMovil(x1, y1, x2, y2, gr, p, vx, vy, (unsigned char)r, (unsigned char)v, (unsigned char)a);	///////Creacion Plataforma Movil
			plataformas3.AgregarP(aux);
		}
		if (opcion == 3) {
			archivo >> x1 >> y1 >> gr >> r >> v >> a >> comentario;
			Moneda* aux = new Moneda(x1, y1, gr, r, v, a);///////Creacion Monedas
			monedas3.AgregarM(aux);
		}
		if (opcion == 4) {
			archivo >> x1 >> y1 >> comentario;
			Sirena* aux = new Sirena(x1, y1);
			enemigos3.AgregarE(aux);
		}
		if (opcion == 5) {
			archivo >> x1 >> y1 >> comentario;
			Pajaro* aux = new Pajaro(x1, y1);
			enemigos3.AgregarE(aux);
		}
		if (opcion == 6) {
			archivo >> x1 >> y1 >> comentario;
			Vector2D* aux = new Vector2D(x1, y1);
			heroe3.AgregarPuntosR(aux);
		}
		if (opcion == 7) {
			archivo >> x1 >> y1 >> pf >> r >> vy >> comentario;
			VidaExtra* aux = new VidaExtra(x1, y1, pf, r, vy);///////Creacion Monedas
			corazones3.AgregarC(aux);
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