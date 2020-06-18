#include "Plataforma.h"
#include "ETSIDI.h"
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
   /* glDisable(GL_LIGHTING);
    glColor3ub(rojo,verde,azul);
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y, 0);       
    glVertex3d(limite2.x, limite2.y, 0);
    glVertex3d(limite2.x, limite2.y - grosor, 0);
    glVertex3d(limite1.x, limite1.y - grosor, 0);
    glEnd();
    */
    if (grosor <= 1) {
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Plataformas2.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);

        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.0);
        glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.0);
        glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.0);
        glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.0);
        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
    }
    else  {
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Plataformas1.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);

        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.0);
        glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.0);
        glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.0);
        glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.0);
        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
    }

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

void Plataforma::Mueve(float t) {

}

void Plataforma::Reaccion(Heroe* pers) {
    pers->SetVel(pers->GetVel().x, 0.0f);
    pers->SetAce(pers->GetAce().x, 0.0f);
}
