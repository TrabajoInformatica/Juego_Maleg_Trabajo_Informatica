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
    if ((diferencia>=altura-0.5f) && (diferencia <=altura) && (pl.Getlimite1().x < posicion.x + altura) && (posicion.x - altura < pl.Getlimite2().x)) {
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
        if ((diferencia1 <= altura)&& (diferencia1>altura-0.5f) && (((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y + altura) &&(pers->GetPos().y + altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y - altura)&&(pers->GetPos().y - altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y < pers->GetPos().y + altura) && (pers->GetPos().y - altura < pl.Getlimite1().y-pl.GetGrosor())))) {
            pers->SetPos(pl.Getlimite1().x - 1.55f, pers->GetPos().y);
            return true;
        }
        if ((diferencia2 <= altura) && (diferencia2 >altura-0.5f) && (((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y + altura) && (pers->GetPos().y + altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y - altura) && (pers->GetPos().y - altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y < pers->GetPos().y + altura) && (pers->GetPos().y - altura < pl.Getlimite1().y -pl.GetGrosor())))) {
            pers->SetPos(pl.Getlimite2().x + 1.5f, pers->GetPos().y);
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
    float distanciar = posicionm.x - m.GetRadio();
    if ((posicion.x + altura >= distanciar) && ( (posicion.y + altura >= posicionm.y - m.GetRadio()) || (posicion.y-altura<=posicionm.y+m.GetRadio()))  ) {
        return true;
    }
    return false;
}
