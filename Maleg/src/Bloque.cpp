#include "Bloque.h"
#include "glut.h"

Bloque::Bloque() {

}

Bloque::Bloque(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
	grosor = gr;
	rojo = r;
	verde = v;
	azul = a;
}

Bloque::~Bloque() {

}

void Bloque:: Dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 0);
	glVertex3d(limite2.x, limite2.y, 0);
	glVertex3d(limite2.x+grosor, limite2.y, 0);
	glVertex3d(limite1.x+grosor, limite1.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}