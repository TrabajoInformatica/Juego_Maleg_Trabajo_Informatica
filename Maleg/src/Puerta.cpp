#include "Puerta.h"
#include "glut.h"
Puerta::Puerta() {

}
Puerta::~Puerta() {
    rojo = 255;
    azul = 0;
    verde = 0;

}
Puerta::Puerta(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a) {
    limite1.x = x1;
    limite1.y = y1;
    limite2.x = x2;
    limite2.y = y2;
    grosor = gr;
    rojo = r;
    verde = v;
    azul = a;
}

void Puerta::Dibuja() {
    glDisable(GL_LIGHTING);
    glColor3ub(rojo, verde, azul);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y, 0);
    glVertex3d(limite2.x, limite2.y, 0);
    glVertex3d(limite2.x, limite2.y - grosor, 0);
    glVertex3d(limite1.x, limite1.y - grosor, 0);
    glEnd();
}
