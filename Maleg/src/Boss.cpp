#include "Boss.h"
#include "ObjetoMovil.h"

Boss::Boss() {

}

Boss::Boss(float x, float y) {

	posicion.x = x;
	posicion.y = y;
	altura = 4.0f;
	velocidad = 0;
	aceleracion = 0;
}

Boss::~Boss() {

}

void Boss::Mueve(float t) {

	ObjetoMovil::Mueve(t);
}

void Boss::Dibuja() {

	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutWireSphere(altura, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

bool Boss::AgregarB(Boss* b) {

	if (num < MAX_BOSS) {
		lista[num] = b;

		num++;

	}
	else return false;
}

void Boss::DestruirContenido(Boss* b) {

	delete b;
	/*for (int i = 0;i < num;i++)
		delete lista[i];*/
}
/*void Boss::SetVida(int v){

	vida = v;
}

int Boss::GetVida() {
	return vida;
}*/

bool Boss::Colision(Heroe* p, Boss b) {
	if (Interaccion::ColisionEnemigo(p, b))
	{
		cout << "colision Boss" << endl;
		//p->SetPos(25.0, 4.0);
		return true;
		//ETSIDI::play("sonidos/estruendo.wav");
	}

	return false;
}

bool Boss::Colision(ListaArmas a, Boss b) {
	for (int i = 0;i < a.GetNum();i++)
	{
		if (Interaccion::ColisionEnemigo(a.GetLista(i), b))
		{
			cout << "colision Arma" << endl;
			return true;
		}
	}
	return false;
}
