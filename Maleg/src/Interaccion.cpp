#include <iostream>
#include "Interaccion.h"
using namespace std;
Interaccion::Interaccion() {

}

Interaccion::~Interaccion() {

}

bool Interaccion::ColisionSup(Personaje* pers, Plataforma pl) {
    Vector2D posicion = pers->GetPos();
    float altura = (pers->GetAltura()) / 2;
    float diferencia = posicion.y - pl.Getlimite1().y;
    if ((diferencia>=altura-1.0f) && (diferencia <=altura) && (pl.Getlimite1().x < posicion.x + altura) && (posicion.x - altura < pl.Getlimite2().x)) {
        pers->SetPos(pers->GetPos().x,pl.Getlimite1().y+altura);
        return true;
    }
    else
        return false;
}

bool Interaccion::ColisionLat(Personaje* pers, Plataforma pl) {
    Vector2D posicion = pers->GetPos();
    float altura = pers->GetAltura() / 2;
     float diferencia1 = pl.Getlimite1().x - posicion.x;
     float diferencia2 = posicion.x - pl.Getlimite2().x;
        if ((pers->GetVel().x>=0)&&(diferencia1 <= altura)&& (diferencia1>altura-0.5f) && (((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y + altura) &&(pers->GetPos().y + altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y - altura)&&(pers->GetPos().y - altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y < pers->GetPos().y + altura) && (pers->GetPos().y - altura < pl.Getlimite1().y-pl.GetGrosor())))) {
            pers->SetPos(pl.Getlimite1().x - altura, pers->GetPos().y);
            return true;
        }
        if ((pers->GetVel().x <= 0)&&(diferencia2 <= altura) && (diferencia2 >altura-0.5f) && (((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y + altura) && (pers->GetPos().y + altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y - altura) && (pers->GetPos().y - altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y < pers->GetPos().y + altura) && (pers->GetPos().y - altura < pl.Getlimite1().y -pl.GetGrosor())))) {
            pers->SetPos(pl.Getlimite2().x + altura, pers->GetPos().y);
            return true;
        }

        return false;
}

bool Interaccion::ColisionInf(Personaje* pers, Plataforma pl) {
   Vector2D posicion = pers->GetPos();
   float altura = pers->GetAltura() / 2;
   float diferencia = pl.Getlimite1().y-pl.GetGrosor() - posicion.y;
   if ((diferencia <= altura) && (diferencia > altura-0.5f) && (pl.Getlimite1().x < pers->GetPos().x + altura) && (pers->GetPos().x - altura < pl.Getlimite2().x)) {
       pers->SetPos(pers->GetPos().x, pl.Getlimite2().y-pl.GetGrosor()-altura);
       return true;
   }
   else
       return false;

}
bool Interaccion::ColisionMoneda(Personaje* pers, Moneda m) {
    Vector2D posicion = pers->GetPos();
    float altura = pers->GetAltura() / 2;
    Vector2D posicionm = m.GetPos();

    float distanciarxi = posicionm.x - m.GetRadio();
    float distanciarxd = posicionm.x + m.GetRadio();
    float distanciapxd = posicion.x + altura;
    float distanciapxi = posicion.x - altura;
    float distanciapysup = posicion.y + altura;
    float distanciapyinf = posicion.y - altura;
    float distanciamsup = posicionm.y + m.GetRadio();
    float distanciaminf = posicionm.y - m.GetRadio();
    if ((distanciarxi <= distanciapxd)&&(distanciarxd>=distanciapxi) && ((distanciapysup >= distanciaminf) && (distanciapyinf <= distanciamsup))) {

        return true;
    }
 

    return false;
}
 bool Interaccion::ColisionEnemigo(Personaje* pers, Enemigo e) {
     Vector2D posicion = pers->GetPos();
     float altura = pers->GetAltura() / 2;
     Vector2D posicione = e.GetPos();
     return false;

}
