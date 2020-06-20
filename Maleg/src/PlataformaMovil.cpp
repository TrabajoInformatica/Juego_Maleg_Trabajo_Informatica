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

void PlataformaMovil::Mueve(float t) {
	tiempo = t;
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
	pers->SetAce(pers->GetAce().x, 0.0f);
	if (velocidad.y < 0 ) {
		pers->SetPos(pers->GetPos().x,pers->GetPos().y + velocidad.y * tiempo);
	}
	if (pers->GetVel().x == 0 ) {
		pers->SetPos(pers->GetPos().x + velocidad.x * tiempo,( pers->GetPos().y));
		pers->SetAce(pers->GetAce().x, 0.0f);
	}
	//cout << "lmi" << limite1.y << endl;
	//cout << "velcidad"<<pers->GetVel().y << endl;
}