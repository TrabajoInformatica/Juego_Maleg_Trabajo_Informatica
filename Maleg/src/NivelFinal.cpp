#include "NivelFinal.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

NivelFinal::NivelFinal() {
	fin = false;

	spawn_enemigos = (10.0f, 10.0f);

	ETSIDI::stopMusica();
	ETSIDI::playMusica("sonidos/Ambiente3.wav");

}

NivelFinal::~NivelFinal() {

}
void NivelFinal::DestruirContenido() {
	monedas.destruirContenido();
	enemigos.DestruirContenido();
	plataformas.DestruirContenido();
	puerta.DestruirContenido();
	corazones.DestruirContenido();
}
Heroe NivelFinal::GetHeroe() {
	heroe.DestruirContenido();
	return heroe;
}

void NivelFinal::Inicializa(Heroe h) {
	heroe = h;
	ONboton = false;
	OFFboton = false;
	/////////////////////////////////////Personaje
	heroe.SetAlturaMuerte(-15.0f);
	heroe.SetPos(0.0f, 10.0f);//160 10
	heroe.SetVel(0.0f, 0.0f);
	//puerta.SetPos(174.0f,8.0f,175.0f,8.0f,-8.0f);
	//puerta.SetColor(255, 0, 0);
	Puerta* puer = new Puerta(200.0f, 30.0f, 204.0f, 30.0f, -5.0f, 255, 0, 0);
	puerta.AgregarP(puer);

	boton.SetPos(51.0, 5.0);
	////////////////////////////////////Inicializa Plataformas, Monedas , Enemigos, Vidas
	LecturaFichero(Fichero);
	Guerreros* gx0 = new Guerreros(15.0f, 4.0f, 5.0f, 2.0f);
	enemigos.AgregarE(gx0);
	Guerreros* gx1 = new Guerreros(20.0f, 4.0f, 6.5f, -2.0f);
	enemigos.AgregarE(gx1);
	boss.SetPos(51.0f, 22.5f);
	boss.SetVida(3);
}

void NivelFinal::Dibuja() {
	// Vista
	gluLookAt(heroe.GetPos().x, heroe.GetPos().y + 1, 3,  // posicion del ojo						//NUNCA MODIFICAR LA Z	No hace fala
		heroe.GetPos().x, heroe.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)			//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// Background
	glEnable(GL_TEXTURE_2D);
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/lvl4background.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-80, -35, 0.6);
	glTexCoord2d(1, 1); glVertex3f(80, -35, 0.6);
	glTexCoord2d(1, 0); glVertex3f(80, 55, 0.6);
	glTexCoord2d(0, 0); glVertex3f(-80, 55, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//Boton Texto F
	ETSIDI::setTextColor(0.0f, 0.0f, 0.0f); //r g b
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("F", 50.0, 6.0);
	// Enemigos
//	if (heroe.GetPos() > spawn_enemigos){

	enemigos.Dibuja();
	// Heroe
	heroe.Dibuja();

	//Plataformas, Monedas y otros.
	plataformas.Dibuja();
	monedas.Dibuja();
	armas.Dibuja();

	corazones.Dibuja();
	puerta.DibujaP();
	//cout << "X" << heroe.GetPos().x << endl;
	//cout << "Y" << heroe.GetPos().y << endl;
	boton.Dibuja();
	boss.Dibuja();

}

void NivelFinal::Mueve() {
	// Enemigos
	enemigos.Mueve(0.025f);
	monedas.Mueve(0.025f);
	armas.Mueve(0.05f);
	plataformas.Mueve(0.025f);

	corazones.Mueve(0.025f);
	// Heroe
	heroe.Mueve(0.1f);

	// Plataforma, Monedas y otros.
	plataformas.Colision(&heroe);
	monedas.Colision(&heroe);
	//enemigos.Colision(&heroe);
	corazones.Colision(&heroe);
	//armas.Colision(&heroe, boss);
	//boss.Colision(armas, boss);
	/////////Provisional

	/*for (int i = 0;i < enemigos.GetNumeroE();i++) {

		if ((enemigos.GetListaEnem(i).Muerte())== true) {
			cout << "me he muerto" << endl;
			enemigos.Eliminar(i);
		}
	}*/

	if (puerta.Colision(&heroe) == true) {
		cout << "puerta" << endl;
		fin = true;
	}
	else
		fin = false;

	for (int i = 0;i < enemigos.GetNumeroE();i++) {
		for (int j = 0;j < armas.GetNum();j++) {
			if (Interaccion::ColisionEnemigo(armas.GetLista(j), enemigos.GetListaEnem(i))) {
				armas.Eliminar(j);
				enemigos.Eliminar(i);
				/*enemigos.GetListaEnem(i).SetVida( enemigos.GetListaEnem(i).GetVida() - 1); 
				cout << "me estan quitando vida" << endl;*/
			}
		}
	}
	for (int j = 0;j < armas.GetNum();j++) {
		if (Interaccion::ColisionEnemigo(armas.GetLista(j), boss)) {
			armas.Eliminar(j);
			if (boss.GetVida() > 0)
				boss.SetVida(boss.GetVida() - 1);
		/*	else {
				cout << "VidaBoss" << boss.GetVida() << endl;		//////FINNNNNNNN
			}*/
		}
	}
}


bool NivelFinal::FinNivelFinal() {
	if (fin == true) {
		return true;
		cout << "ha pasado" << endl;
	}
	else
		return false;
}

void NivelFinal::Tecla(unsigned char key) {
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

	////////Hitbox
	if (key == '1' && estado == ShowHitbox) {
		estado = HideHitbox;
	}
	else if (key == '1' && estado == HideHitbox) {
		estado = ShowHitbox;
	}
	if (estado == ShowHitbox) {
		heroe.ShowHitbox(true);
		enemigos.ShowHitbox(true);
	}
	else {
		heroe.ShowHitbox(false);
		enemigos.ShowHitbox(false);
	}

	if (key == ' ') {
		if (heroe.ValidarDisparo()) {
			ETSIDI::play("sonidos/DisparoFlecha.mp3");
			if (heroe.Disparo()) {
				Lanza* aux = new Lanza(heroe.GetPos().x + heroe.GetAltura(), heroe.GetPos().y, 10);
				armas.AgregarA(aux);
				heroe.SumarMonedas(false);
			}
			else if (!heroe.Disparo()) {
				Lanza* aux = new Lanza(heroe.GetPos().x - heroe.GetAltura(), heroe.GetPos().y, -10);
				armas.AgregarA(aux);
				heroe.SumarMonedas(false);
			}
		}
	}
	if ((key=='F'||key=='f')&&boton.Colision(&heroe, boton) == true && OFFboton == false && enemigos.GetNumeroE()==0) {
		PlataformaMovil* auxi = new PlataformaMovil(21.0, 7.0, 25.0, 7.0, 0.5, 180, 3.5, 2.1, 128.0, 64.0, 0.0);	///////Creacion Plataforma Movil
		plataformas.AgregarP(auxi);
		ONboton = true;
		OFFboton = true;
	}
	else {
		ONboton = false;

	}
}

void NivelFinal::TeclaUp(unsigned char key) {
	if (key == 'a')
		heroe.SetVel(0.0f, heroe.GetVel().y);
	if (key == 'd')
		heroe.SetVel(0.0f, heroe.GetVel().y);
}

bool NivelFinal::MuerteHeroe() {
	if (heroe.Muerte()) {
		cout << "Muerto" << endl;
		heroe.DestruirContenido();
		return true;
	}
	else
		return false;
}

void NivelFinal::LecturaFichero(string Fichero) {
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
		if (opcion == 6) {
			archivo >> x1 >> y1 >> comentario;
			Vector2D* aux = new Vector2D(x1, y1);
			heroe.AgregarPuntosR(aux);
		}
		if (opcion == 7) {
			archivo >> x1 >> y1 >> pf >> r >> vy >> comentario;
			VidaExtra* aux = new VidaExtra(x1, y1, pf, r, vy);///////Creacion Monedas
			corazones.AgregarC(aux);
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