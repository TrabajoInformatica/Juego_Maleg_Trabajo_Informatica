#include "Boss.h"
#include "ObjetoMovil.h"

Boss::Boss():boss("imagenes/minotauro.png", 9, 5) {
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
	//Dimensiones del sprite
	boss.setCenter(5, 5);
	boss.setSize(10, 10);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	//if (velocidad.x > 0.01)boss.flip(false, false);
	//if (velocidad.x < -0.01)boss.flip(true, false);
	boss.flip(true, false);
	boss.draw();
	boss.loop();
	glPopMatrix();

	
	glPushMatrix();
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutWireSphere(altura, 40, 40);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
	
}

void Boss::SetVida(int v) {
	vida = v;
}

int Boss::GetVida() {
	return vida;
}

bool Boss::Colision(Heroe* p, Boss b) {
	if (Interaccion::ColisionEnemigo(p, b))
	{
		cout << "colision Boss" << endl;
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
