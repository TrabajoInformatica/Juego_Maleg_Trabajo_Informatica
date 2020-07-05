#include "NivelFinal.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

NivelFinal::NivelFinal() {
	fin = false;
	invocar = false;

	spawn_enemigos = (10.0f, 10.0f);

	ETSIDI::stopMusica();
	ETSIDI::playMusica("sonidos/Ambiente3.wav");

}

NivelFinal::~NivelFinal() {

}
void NivelFinal::DestruirContenido() {
	monedas.destruirContenido();
	ciclopes.DestruirContenido();
	bolasdefuego.DestruirContenido();
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
	ciclopes.AgregarE(gx0);
	Guerreros* gx1 = new Guerreros(20.0f, 4.0f, 6.5f, -2.0f);
	ciclopes.AgregarE(gx1);
	Guerreros* gx2 = new Guerreros(17.0f, 4.0f, 4.0f, 3.0f);
	ciclopes.AgregarE(gx2);
	Guerreros* gx3 = new Guerreros(22.0f, 4.0f, 3.0f, -3.0f);
	ciclopes.AgregarE(gx3);
	Guerreros* gx4 = new Guerreros(32.0f, 4.0f, 10.0f, 2.5f);
	ciclopes.AgregarE(gx4);
	Guerreros* gx5 = new Guerreros(40.0f, 4.0f, 12.0f, -3.0f);
	ciclopes.AgregarE(gx5);
	Guerreros* gx6 = new Guerreros(48.0f, 4.0f, 7.0f, 2.5f);
	ciclopes.AgregarE(gx6);
	Guerreros* gx7 = new Guerreros(27.0f, 4.0f, 7.0f, -2.0f);
	ciclopes.AgregarE(gx7);
	Guerreros* gx8 = new Guerreros(30.0f, 4.0f, 15.0f, 3.5f);
	ciclopes.AgregarE(gx8);
	Guerreros* gx9 = new Guerreros(33.0f, 4.0f, 8.0f, -2.5f);
	ciclopes.AgregarE(gx9);

	BolaFuego* b0 = new BolaFuego(13.0, 63.0, -1.0);
	bolasdefuego.AgregarE(b0);
	BolaFuego* b1 = new BolaFuego(20.0, 69.0, -1.0);
	bolasdefuego.AgregarE(b1);
	BolaFuego* b2 = new BolaFuego(9.0, 76.0, -1.5);
	bolasdefuego.AgregarE(b2);
	BolaFuego* b3 = new BolaFuego(25.0, 83.0, -1.5);
	bolasdefuego.AgregarE(b3);
	BolaFuego* b4 = new BolaFuego(29.0, 85.0, -1.0);
	bolasdefuego.AgregarE(b4);
	BolaFuego* b5 = new BolaFuego(33.0, 90.0, -1.0);
	bolasdefuego.AgregarE(b5);
	BolaFuego* b6 = new BolaFuego(15.0, 90.0, -1.0);
	bolasdefuego.AgregarE(b6);
	BolaFuego* b7 = new BolaFuego(40.0, 97.0, -1.0);
	bolasdefuego.AgregarE(b7);
	BolaFuego* b8 = new BolaFuego(44.0, 102.0, -0.6);
	bolasdefuego.AgregarE(b8);
	BolaFuego* b9 = new BolaFuego(16.0, 104.0, -1.0);
	bolasdefuego.AgregarE(b9);
	BolaFuego* b10 = new BolaFuego(26.0, 105.0, -1.0);
	bolasdefuego.AgregarE(b10);
	BolaFuego* b11 = new BolaFuego(37.0, 105.0, -1.0);
	bolasdefuego.AgregarE(b11);
	BolaFuego* b12 = new BolaFuego(45.0, 107.0, -1.5);
	bolasdefuego.AgregarE(b12);
	BolaFuego* b13 = new BolaFuego(40.0, 109.0, -1.0);
	bolasdefuego.AgregarE(b13);
	BolaFuego* b14 = new BolaFuego(20.0, 119.0, -1.0);
	bolasdefuego.AgregarE(b14);
	BolaFuego* b15 = new BolaFuego(10.0, 119.0, -1.0);
	bolasdefuego.AgregarE(b15);
	BolaFuego* b16 = new BolaFuego(33.0, 124.0, -1.0);
	bolasdefuego.AgregarE(b16);
	BolaFuego* b17 = new BolaFuego(37.0, 129.0, -1.5);
	bolasdefuego.AgregarE(b17);
	BolaFuego* b18 = new BolaFuego(25.0, 132.0, -1.0);
	bolasdefuego.AgregarE(b18);
	BolaFuego* b19 = new BolaFuego(40.0, 133.0, -1.5);
	bolasdefuego.AgregarE(b19);
	BolaFuego* b20 = new BolaFuego(18.0, 140.0, -1.0);
	bolasdefuego.AgregarE(b20);
	BolaFuego* b21 = new BolaFuego(25.0, 142.0, -1.0);
	bolasdefuego.AgregarE(b21);
	BolaFuego* b22 = new BolaFuego(42.0, 145.0, -1.0);
	bolasdefuego.AgregarE(b22);
	BolaFuego* b23 = new BolaFuego(33.0, 145.0, -1.0);
	bolasdefuego.AgregarE(b23);
	BolaFuego* b24 = new BolaFuego(37.0, 149.0, -1.0);
	bolasdefuego.AgregarE(b24);
	BolaFuego* b25 = new BolaFuego(25.0, 150.0, -1.0);
	bolasdefuego.AgregarE(b25);

	boss.SetPos(51.0f, 22.5f);
	boss.SetVida(5);
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
	ETSIDI::setTextColor(255.0f, 255.0f, 255.0f); //r g b
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("F", 50.0, 6.0);
	//Texto intro nivel 4
	ETSIDI::setTextColor(255.0f, 255.0f, 255.0f); //r g b
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12.5);
	ETSIDI::printxy("Acaba con los enemigos", -10.0, 14.0);
	ETSIDI::printxy("y busca una manera de", -10.0, 13.0);
	ETSIDI::printxy("llegar hasata el BOSS", -10.0, 12.0);
	//Texto pulsar boton
	if (OFFboton == false) {
		ETSIDI::setTextColor(255.0f, 255.0f, 255.0f); //r g b
		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("Pulsa F para activar", 52.0, 6.0);
		ETSIDI::printxy("la plataforma", 53.0, 5.0);
	}
	else 
	{
		ETSIDI::setTextColor(255.0f, 255.0f, 255.0f); //r g b
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12.5);
		ETSIDI::printxy("             ", -10.0, 14.0);
	}
	// Enemigos
//	if (heroe.GetPos() > spawn_enemigos){

	ciclopes.Dibuja();
	bolasdefuego.Dibuja();
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
	ciclopes.Mueve(0.025f);
	bolasdefuego.Mueve(0.025f);
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
	/////////Provisional

	if (bolasdefuego.GetNumeroE() == 0 && invocar==true) {
		BolaFuego* b0 = new BolaFuego(13.0, 63.0, -1.0);
		bolasdefuego.AgregarE(b0);
		BolaFuego* b1 = new BolaFuego(20.0, 69.0, -1.0);
		bolasdefuego.AgregarE(b1);
		BolaFuego* b2 = new BolaFuego(9.0, 76.0, -1.5);
		bolasdefuego.AgregarE(b2);
		BolaFuego* b3 = new BolaFuego(25.0, 83.0, -1.5);
		bolasdefuego.AgregarE(b3);
		BolaFuego* b4 = new BolaFuego(29.0, 85.0, -1.0);
		bolasdefuego.AgregarE(b4);
		BolaFuego* b5 = new BolaFuego(33.0, 90.0, -1.0);
		bolasdefuego.AgregarE(b5);
		BolaFuego* b6 = new BolaFuego(15.0, 90.0, -1.0);
		bolasdefuego.AgregarE(b6);
		BolaFuego* b7 = new BolaFuego(40.0, 97.0, -1.0);
		bolasdefuego.AgregarE(b7);
		BolaFuego* b8 = new BolaFuego(44.0, 102.0, -0.6);
		bolasdefuego.AgregarE(b8);
		BolaFuego* b9 = new BolaFuego(16.0, 104.0, -1.0);
		bolasdefuego.AgregarE(b9);
		BolaFuego* b10 = new BolaFuego(26.0, 105.0, -1.0);
		bolasdefuego.AgregarE(b10);
		BolaFuego* b11 = new BolaFuego(37.0, 105.0, -1.0);
		bolasdefuego.AgregarE(b11);
		BolaFuego* b12 = new BolaFuego(45.0, 107.0, -1.5);
		bolasdefuego.AgregarE(b12);
		BolaFuego* b13 = new BolaFuego(40.0, 109.0, -1.0);
		bolasdefuego.AgregarE(b13);
		BolaFuego* b14 = new BolaFuego(20.0, 119.0, -1.0);
		bolasdefuego.AgregarE(b14);
		BolaFuego* b15 = new BolaFuego(10.0, 119.0, -1.0);
		bolasdefuego.AgregarE(b15);
		BolaFuego* b16 = new BolaFuego(33.0, 124.0, -1.0);
		bolasdefuego.AgregarE(b16);
		BolaFuego* b17 = new BolaFuego(37.0, 129.0, -1.5);
		bolasdefuego.AgregarE(b17);
		BolaFuego* b18 = new BolaFuego(25.0, 132.0, -1.0);
		bolasdefuego.AgregarE(b18);
		BolaFuego* b19 = new BolaFuego(40.0, 133.0, -1.5);
		bolasdefuego.AgregarE(b19);
		BolaFuego* b20 = new BolaFuego(18.0, 140.0, -1.0);
		bolasdefuego.AgregarE(b20);
		BolaFuego* b21 = new BolaFuego(25.0, 142.0, -1.0);
		bolasdefuego.AgregarE(b21);
		BolaFuego* b22 = new BolaFuego(42.0, 145.0, -1.0);
		bolasdefuego.AgregarE(b22);
		BolaFuego* b23 = new BolaFuego(33.0, 145.0, -1.0);
		bolasdefuego.AgregarE(b23);
		BolaFuego* b24 = new BolaFuego(37.0, 149.0, -1.0);
		bolasdefuego.AgregarE(b24);
		BolaFuego* b25 = new BolaFuego(25.0, 150.0, -1.0);
		bolasdefuego.AgregarE(b25);
		 invocar = false;
		 sumac -= 5;
	}
	if (bolasdefuego.GetNumeroE()==0) {
		invocar = true;
	}
	for (int i = 0;i < bolasdefuego.GetNumeroE();i++) {
		if (bolasdefuego.GetListaEnem(0).GetPos().y < -5.0f) {
			bolasdefuego.Eliminar(i);
		}
	}
		for (int i = 0;i < ciclopes.GetNumeroE();i++) {
			for (int j = 0;j < armas.GetNum();j++) {
				if (Interaccion::ColisionEnemigo(armas.GetLista(j), ciclopes.GetListaEnem(i))) {
					armas.Eliminar(j);
					ciclopes.Eliminar(i);
				}
			}
		}
	for (int j = 0;j < armas.GetNum();j++) {
		if (Interaccion::ColisionEnemigo(armas.GetLista(j), boss)) {
			armas.Eliminar(j);
			boss.SetVida(boss.GetVida() - 1);
			cout << "Vida boss" << boss.GetVida() << endl;
			if (boss.GetVida() > 0) {
				ETSIDI::playMusica("sonidos/Atacado.wav");
				boss.SetVida(boss.GetVida() - 1);
				invocar = true;
				heroe.SetPos(17.0f, 4.0f);
			}
			else if (boss.GetVida() == 0) fin = true;
		}
	}
}


bool NivelFinal::FinNivelFinal() {
	if (fin == true) {
		heroe.DestruirContenido();
		heroe.SetMonedas(0);
		return true;
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
		ciclopes.ShowHitbox(true);
		bolasdefuego.ShowHitbox(true);
	}
	else {
		heroe.ShowHitbox(false);
		ciclopes.ShowHitbox(false);
		bolasdefuego.ShowHitbox(false);
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
	if ((key=='F'||key=='f')&&boton.Colision(&heroe, boton) == true && OFFboton == false) {
		ETSIDI::playMusica("sonidos/Estruendo.wav");
		PlataformaMovil* auxi = new PlataformaMovil(21.0, 7.0, 25.0, 7.0, 0.5, 120, 5.1, 3.6, 128.0, 64.0, 0.0);	///////Creacion Plataforma Movil
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
			ciclopes.AgregarE(aux);
		}
		if (opcion == 5) {
			archivo >> x1 >> y1 >> comentario;
			Pajaro* aux = new Pajaro(x1, y1);
			ciclopes.AgregarE(aux);
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