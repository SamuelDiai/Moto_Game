

#include "voiture.h"
const FVector<float,2> gravity(0,0.07);
void Balle::afficher_balle()
{
    fillCircle(largeur/3,pos.y(),r,BLUE);
}

void Balle::effacer_balle()
{
    fillCircle(largeur/3,pos.y(),r,WHITE);
}

void Balle::addition(FVector<float,2> vec)
{
    pos+=vec;
}

Balle::Balle()
{
    FVector<float,2> p(largeur/3,r);
    FVector<float,2> vit(2,0);
    pos=p;
    vitesse=vit;
}

void Balle::update_air()
{

   vitesse+= dt*gravity;
   pos+= dt*vitesse;
}

FVector<float, 2> Balle::getpos()
{
    return pos;
}
int Balle::getvitx()
{
    return vitesse.x();
}
int Balle::getvity()
{
    return vitesse.y();
}
