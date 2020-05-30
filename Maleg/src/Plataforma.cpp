#include "Plataforma.h"
#include "glut.h"

Plataforma::Plataforma() {

}

Plataforma::Plataforma(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a) {
    limite1.x = x1;
    limite1.y = y1;
    limite2.x = x2;
    limite2.y = y2;
    grosor = gr;
    rojo = r;
    verde = v;
    azul = a;
}

Plataforma::~Plataforma() {

}

void Plataforma::SetPos(float x1, float y1 ,float x2,float y2,float gr) {
	limite1.x = x1;
	limite1.y = y1; 
	limite2.x = x2;
	limite2.y = y2;
    grosor = gr;
}

void Plataforma::SetColor(unsigned char r, unsigned char v, unsigned char a) {
    rojo = r;
    verde = v;
    azul = a;
}

Vector2D Plataforma::Getlimite1() {
    return limite1;
}

Vector2D Plataforma::Getlimite2() {
    return limite2;
}

float Plataforma::GetGrosor() {
    return grosor;
}

void Plataforma::Dibuja() {
    glDisable(GL_LIGHTING);
    glColor3ub(rojo,verde,azul);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y, 0);       
    glVertex3d(limite2.x, limite2.y, 0);
    glVertex3d(limite2.x, limite2.y - grosor, 0);
    glVertex3d(limite1.x, limite1.y - grosor, 0);
    glEnd();
    glEnable(GL_LIGHTING);
}

float Plataforma::distancia(Vector2D punto, Vector2D* direccion){
    Vector2D u = (punto - limite1);
    Vector2D v = (limite2 - limite1).unitario();
    float longitud = (limite1 - limite2).modulo();
    Vector2D dir;
    float valor = u * v;
    float distancia = 0;
    if (valor < 0)
        dir = u;
    else if (valor > longitud)
        dir = (punto - limite2);
    else {
        Vector2D s;
        s = v * valor;
        dir = u - s;
    }
    distancia = dir.modulo();
    if (direccion != 0) //si nos dan un vector…
        *direccion = dir.unitario();
    return distancia;
}
