#include "Nivel1.h"
#include "glut.h"

Nivel1::Nivel1() {

}

Nivel1::~Nivel1() {
	plataformas.DestruirContenido();
}

void Nivel1::Inicializa() {
	/////////////////////////////////////Personaje
	//persona.setpos(0.0f, 0.0f);
	//persona.setvel(1.0f, 0.0f);
	sirena.SetAltura(2.0f);
	sirena.SetPos(27.5f, 2.0f);
	sirena.SetVel(0.0f, 2.0f);
	////////////////////////////////////Plataformas

	plataformas.LecturaFichero(Fichero);
	//moneda1.SetPos(12.5, 5.0);//Inicializacion por fichero de objetos plataforma y bloque 
	//moneda2.SetPos(15.0, 6.0);
	//moneda3.SetPos(65.0, -5.0);
	//moneda4.SetPos(12.5, 8.0);
	///////////////////////////////////Enemigos
	Moneda* aux0 = new Moneda();
	aux0->SetPos(12.5, 5.0);//es la segunda
	monedas.agregar(aux0);
	Moneda* aux = new Moneda();
	aux->SetPos(40.0,14.0);//es la segunda
	monedas.agregar(aux);
	Moneda* aux1 = new Moneda();
	aux1->SetPos(81.5, 14.0);
	monedas.agregar(aux1);
	Moneda* aux2 = new Moneda();
	aux2->SetPos(53.0, 8.0);
	monedas.agregar(aux2);
	Moneda* aux3 = new Moneda();
	aux3->SetPos(125.0, 16.5);
	monedas.agregar(aux3);
}

void Nivel1::Dibuja() {
	//////////////////////////////////////Vista
	gluLookAt(heroe.GetPos().x,heroe.GetPos().y+ 1, 3,  // posicion del ojo						//NUNCA MODIFICAR LA Z	No hace fala
		heroe.GetPos().x, heroe.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)			//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	/////////////////////////////////////Personaje
	heroe.Dibuja();
	sirena.Dibuja();
	////////////////////////////////////Plataformas
	plataformas.Dibuja();
	monedas.Dibuja();
	marcador.Dibuja(&heroe);
	///////////////////////////////////Enemigos
}
void Nivel1::mueve(float t) {


	monedas.Mueve(0.020f);
	sirena.Mueve(0.025f);
	heroe.Mueve(0.025f);
	plataformas.Colision(&heroe);
	monedas.Colision(&heroe);
}

void Nivel1::Tecla(unsigned char key) {
	if (key == 'd')
		heroe.SetVel(8.0f, heroe.GetVel().y);
	if (key == 'a')
		heroe.SetVel(-8.0f, heroe.GetVel().y);
	if (key == 'w') {
		heroe.SetVel(heroe.GetVel().x, 10.0f);
	}
}


/////////////////////////////////////Personaje

////////////////////////////////////Plataformas
/*
horiz1.SetPos(-10.0f, 0.0f, 10.0f, 0.0f);				//SueloInicial
horiz1.SetColor(128.0, 64.0, 0.0);						///
esc1_p1.SetPos(10.0f, 0.0f, 10.0f, 3.0f, 5.0f);			//Escalera1 Pelda�o 1
esc1_p1.SetColor(128.0, 64.0, 0.0);						///
esc1_p2.SetPos(15.0f, 3.0f, 15.0f, 6.0f, 5.0f);			//Escalera1 Pelda�o2 2
esc1_p2.SetColor(128.0, 64.0, 0.0);
horiz2.SetPos(15.0f, 6.0f, 25.0f, 6.0f);				//Fin de la escalera,
horiz2.SetColor(128.0, 64.0, 0.0);
charco.SetPos(25.0f, 6.0f, 30.0f, 6.0f);				//Agua Primera sirena
charco.SetColor(85.0, 100.0, 235.0);
horiz3.SetPos(30.0f, 6.0f, 35.0f, 6.0f);				//Suelo de tierra entre las sirenas
horiz3.SetColor(128.0, 64.0, 0.0);
charco2.SetPos(35.0f, 6.0f, 45.0f, 6.0f);				//Agua donde se encuentran las dos sirenas
charco2.SetColor(85.0, 100.0, 235.0);					//
elevada.SetPos(35.0f, 11.0f, 45.0f, 11.0f);				//Plataforma elevada encima de las dos sirenas
elevada.SetColor(128.0, 64.0, 0.0);						//
horiz4.SetPos(45.0f, 6.0f, 55.0f, 6.0f);				//Suelo despues de las 2 sirenas
horiz4.SetColor(128.0, 64.0, 0.0);						//
cuadrado1.SetPos(55.0f, 6.0f, 55.0f, 9.0f, 3.0f);		//SaltosCuadrados1 cuadrado1
cuadrado1.SetColor(128.0, 64.0, 0.0);					//
cuadrado2.SetPos(50.0f, 12.0f, 50.0f, 15.0f, 3.0f);		////SaltosCuadrados1 cuadrado2
cuadrado2.SetColor(128.0, 64.0, 0.0);
horiz5.SetPos(55.0f, 18.0f, 70.0f, 18.0f);				//Plataforma despues de los cuadrados de salto con pajaro encima y agua debajo
horiz5.SetColor(128.0, 64.0, 0.0);						//
horiz6.SetPos(58.0f, 6.0f, 110.0f, 6.0f);				///////IMP///////////Agua debajo plataforma pajaros
horiz6.SetColor(85.0, 100.0, 235.0);						//
horiz7.SetPos(73.0f, 15.0f, 76.0f, 15.0f);				//Salto1 encima del agua despues de plataforma pajaros
horiz7.SetColor(128.0, 64.0, 0.0);						//
horiz8.SetPos(77.0f, 11.0f, 80.0f, 11.0f);				//Salto2
horiz8.SetColor(128.0, 64.0, 0.0);						//
horiz9.SetPos(84.0f, 14.0f, 86.0f, 14.0f);				//Salto3
horiz9.SetColor(128.0, 64.0, 0.0);						//

horiz10.SetPos(87.0f, 18.0f, 93.0f, 18.0f);				//Plataforma1 despues de saltos
horiz10.SetColor(128.0, 64.0, 0.0);						//
horiz11.SetPos(96.0f, 14.0f, 99.0f, 14.0f);				//Plataforma2
horiz11.SetColor(128.0, 64.0, 0.0);						//
horiz12.SetPos(104.0f, 10.0f, 107.0f, 10.0f);			//Plataforma3
horiz12.SetColor(128.0, 64.0, 0.0);						//

paredvertical.SetPos(110.0f, 6.0f, 110.0f, 11.0f, 2);	//Pared Vertical al final antes de cueva
paredvertical.SetColor(128.0, 64.0, 0.0);				//
horiz13.SetPos(112.0f, 15.0f, 130.0f, 15.0f);				//Cueva techo
horiz13.SetColor(128.0, 64.0, 0.0);						//
horiz14.SetPos(112.0f, 11.0f, 130.0f, 11.0f);				//Cueva suelo
horiz14.SetColor(128.0, 64.0, 0.0);						//
*/
///////////////////////////////////Enemigos


//Dibuja
	/*
	horiz1.Dibuja();
	esc1_p1.Dibuja();
	esc1_p2.Dibuja();
	horiz2.Dibuja();
	charco.Dibuja();
	horiz3.Dibuja();
	elevada.Dibuja();
	charco2.Dibuja();
	horiz4.Dibuja();
	cuadrado1.Dibuja();
	cuadrado2.Dibuja();
	horiz5.Dibuja();
	horiz6.Dibuja();
	horiz7.Dibuja();
	horiz8.Dibuja();
	horiz9.Dibuja();
	horiz10.Dibuja();
	horiz11.Dibuja();
	horiz12.Dibuja();
	paredvertical.Dibuja();
	horiz13.Dibuja();
	horiz14.Dibuja();
	*/

