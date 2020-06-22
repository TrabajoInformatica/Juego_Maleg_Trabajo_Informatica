#include "Nivel2.h"
#include <iostream>
#include "glut.h"
using namespace std;

Nivel2::Nivel2() {

}

Nivel2::~Nivel2() {
	plataformas.DestruirContenido();
}

void Nivel2::Inicializa(int vidas) {
	
	/////////////////////////////////////Personaje
	heroe2.SetVida(vidas); //si se hace con el mismo heroe no 
	heroe2.SetPos(0.0f, 0.0f);
	heroe2.SetVel(0.0f, 0.0f);
	//heroe2.SetAlturaMuerte(-15.0f);
	////////////////////////////////////Plataformas


	///////////////////////////////////Enemigos
	
	Moneda* aux0 = new Moneda();
	aux0->SetPos(12.0, 20.0);//es la segunda
	monedas2.AgregarM(aux0);
	Moneda* aux = new Moneda();
	aux->SetPos(39.0, 30.0);//es la segunda
	monedas2.AgregarM(aux);
	Moneda* aux1 = new Moneda();
	aux1->SetPos(87.0, 35.5);
	monedas2.AgregarM(aux1);
	Moneda* aux2 = new Moneda();
	aux2->SetPos(104.0, 27.0);
	monedas2.AgregarM(aux2);
	Moneda* aux3 = new Moneda();
	aux3->SetPos(19.0, 3.5);
	monedas2.AgregarM(aux3);
	
}

void Nivel2::Dibuja() {
	gluLookAt(heroe2.GetPos().x, heroe2.GetPos().y + 1, 3,  // posicion del ojo						//NUNCA MODIFICAR LA Z	No hace fala
		heroe2.GetPos().x, heroe2.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)			//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);
	/////////////////////////////////////Personaje
	cout << "estoy dibujado nivel 2" << endl;
////////////////////////////////////Plataformas
	heroe2.Dibuja();
	plataformas.Dibuja();
	monedas2.Dibuja();



	///////////////////////////////////Enemigos
}
void Nivel2::Mueve() {
	monedas2.Mueve(0.025f);
	//sirena.Mueve(0.025f);
	heroe2.Mueve(0.05f);
	plataformas.Colision(&heroe2);
	Moneda* aux = monedas2.Colision(&heroe2);
	if (aux != 0)//si alguna esfera ha chocado con el hombre
		monedas2.Eliminar(aux);

}

void Nivel2::Tecla(unsigned char key) {
	if (key == 'w') {
		for (int i = 0; i < plataformas.GetNumPlat(); i++) {
			if (Interaccion::ColisionSup(&heroe2, plataformas.GetListaPlat(i))) {
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
		heroe2.SetPos(0.0f, 3.0f);
		heroe2.SetVel(0.0f, 0.0f);
		return true;
	}
	else
		return false;
}
/*
/////////////////////////////////////Personaje

////////////////////////////////////Plataformas
hor1.SetPos(-10.0, 0.0, 20.0, 0.0); //Plataforma base inicial
hor1.SetColor(155.0, 155.0, 155.0);
blo1.SetPos(17.0, 5.0, 17.0, 8.0, 3.0); //Primer bloque en la primera pared vertical
blo1.SetColor(155.0, 155.0, 155.0);
flot1.SetPos(10.0, 10.5, 14.0, 10.5); //Primera plataforma flotante
flot1.SetColor(155.0, 155.0, 155.0);
blo2.SetPos(17.0, 13.0, 17.0, 16.0, 3.0); //Segundo bloque en la pared vertical
blo2.SetColor(155.0, 155.0, 155.0);
flot2.SetPos(10.0, 18.5, 14.0, 18.5); //Segunda plataforma flotante
flot2.SetColor(155.0, 155.0, 155.0);
ver1.SetPos(20.0, 0.0, 20.0, 20.0); //Primera pared vertical
ver1.SetColor(155.0, 155.0, 155.0);
hor2.SetPos(20.0,20.0,25.0,20.0); //Continuaci�n despues de los saltos
hor2.SetColor(155.0, 155.0, 155.0);
hoyo.SetPos(25.0, 20.0, 32.0, 20.0); //Cavidad en el suelo
hoyo.SetColor(0.0, 255.0, 127.0);
flot3.SetPos(27.5, 23.0, 32.5, 23.0); //Plataforma flotante encima del suelo
flot3.SetColor(155.0, 155.0, 155.0);
blo3.SetPos(35.0, 25.0, 35.0, 27.0, 3.0); //Bloque flotante
blo3.SetColor(155.0, 155.0, 155.0);
blo4.SetPos(41.0, 29.0 ,41.0, 31.0,3.0); //Bloque flotante a continuaci�n del anterior
blo4.SetColor(155.0, 155.0, 155.0);
blo5.SetPos(47.0, 25.0, 47.0, 27.0,3.0); //Bloque flotante a continuaci�n del anterior
blo5.SetColor(155.0, 155.0, 155.0);
hor3.SetPos(52.0, 29.0, 57.0, 29.0); //Zona de "descanso" despu�s de los saltos
hor3.SetColor(155.0, 155.0, 155.0);
hoyo2.SetPos(53.0, 25.0, 60.0, 25.0);
hoyo2.SetColor(0.0, 255.0, 127.0);//Hoyo debajo de la plataforma anterior
hor4.SetPos(60.0, 25.0, 73.0, 25.0); //Plataforma
hor4.SetColor(155.0, 155.0, 155.0);
esc1.SetPos(65.0, 25.0, 65.0, 27.0, 2.0); //Pelda�os de las escaleras
esc1.SetColor(155.0, 155.0, 155.0);
esc2.SetPos(67.0, 27.0, 67.0, 29.0, 2.0);
esc2.SetColor(155.0, 155.0, 155.0);
esc3.SetPos(69.0, 29.0, 69.0, 31.0, 2.0);
esc3.SetColor(155.0, 155.0, 155.0);
esc4.SetPos(71.0, 31.0, 71.0, 33.0, 2.0);
esc4.SetColor(155.0, 155.0, 155.0);
esc5.SetPos(73.0, 33.0, 73.0, 35.0, 2.0);
esc5.SetColor(155.0, 155.0, 155.0);
esc6.SetPos(75.0, 35.0, 75.0, 37.0, 2.0);
esc6.SetColor(155.0, 155.0, 155.0);
ver3.SetPos(77.0, 25.0, 77.0, 37.0); //Cierre de la escalera
ver3.SetColor(155.0, 155.0, 155.0);
blo6.SetPos(81.0, 25.0, 81.0, 40.0, 4.0); //Rectangulo grande
blo6.SetColor(155.0, 155.0, 155.0);
hoyo3.SetPos(85.0, 25.0, 88.0, 25.0); //Hoyo a continuacion del rectangulo
hoyo3.SetColor(0.0, 255.0, 127.0);
hor5.SetPos(88.0, 25.0, 93.0, 25.0);
hor5.SetColor(155.0, 155.0, 155.0);
flot4.SetPos(95.0, 28.0, 100.0, 28.0);//Plataformas flotantantes
flot4.SetColor(155.0, 155.0, 155.0);
flot5.SetPos(102.0, 26.0, 106.0, 26.0);
flot5.SetColor(155.0, 155.0, 155.0);
flot6.SetPos(102.0, 30.0, 106.0, 30.0);
flot6.SetColor(155.0, 155.0, 155.0);
blo7.SetPos(108.0, 27.0, 108.0, 29.0, 2.0); //Bloque
blo7.SetColor(155.0, 155.0, 155.0);

//////////////////////////////////Enemigos
*/
/*
	hor1.Dibuja();
	blo1.Dibuja();
	flot1.Dibuja();
	blo2.Dibuja();
	flot2.Dibuja();
	ver1.Dibuja();
	hor2.Dibuja();
	hoyo.Dibuja();
	flot3.Dibuja();
	blo3.Dibuja();
	blo4.Dibuja();
	blo5.Dibuja();
	hor3.Dibuja();
	hoyo2.Dibuja();
	hor4.Dibuja();
	esc1.Dibuja();
	esc2.Dibuja();
	esc3.Dibuja();
	esc4.Dibuja();
	esc5.Dibuja();
	esc6.Dibuja();
	ver3.Dibuja();
	blo6.Dibuja();
	hoyo3.Dibuja();
	hor5.Dibuja();
	flot4.Dibuja();
	flot6.Dibuja();
	blo7.Dibuja();
	*/
