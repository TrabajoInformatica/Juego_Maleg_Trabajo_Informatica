#include "PlataformaMovil.h"
#include <iostream>
#include "glut.h"
using namespace std;
PlataformaMovil::PlataformaMovil() {

}

PlataformaMovil::PlataformaMovil(float x1, float y1, float x2, float y2, float gr, float p, float vx, float vy, unsigned char r, unsigned char v, unsigned char a) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
	grosor = gr;
	rojo = r;
	verde = v;
	azul = a;
	velocidad.x = vx;
	velocidad.y = vy;
	contador = 0;
	paso = p;
}

PlataformaMovil::~PlataformaMovil() {

}
void PlataformaMovil::Dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 0);
	glVertex3d(limite2.x, limite2.y, 0);
	glVertex3d(limite2.x, limite2.y - grosor, 0);
	glVertex3d(limite1.x, limite1.y - grosor, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}


void PlataformaMovil::Mueve(float t) {
	if (contador < paso) {
		if (velocidad.x != 0) {
			limite1.x = limite1.x + velocidad.x * t;
			limite2.x = limite2.x + velocidad.x * t;
		}
		if (velocidad.y != 0) 
			limite2.y = limite1.y = limite1.y + velocidad.y * t;
	}
	else if (contador >= paso) {
		contador = 0;
		velocidad.x = -velocidad.x;
		velocidad.y = -velocidad.y;
	}
	contador++;
}

void PlataformaMovil::Reaccion(Heroe* pers) {
	if (velocidad.y < 0) {
		pers->SetVel(pers->GetVel().x, velocidad.y);
		pers->SetAce(pers->GetAce().x, 0.0f);
	}
	else{
		pers->SetVel(pers->GetVel().x, 0.0f);
		pers->SetAce(pers->GetAce().x, 0.0f);
	}
}