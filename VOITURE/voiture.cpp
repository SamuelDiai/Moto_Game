

#include "voiture.h"
const FVector<float,2> gravity(0,0.03);

void Balle::afficher_balle()
{
    fillCircle(largeur/3,hauteur/3+pos.y(),r,BLUE);
}

void Balle::effacer_balle()
{
    fillCircle(largeur/3,hauteur/3+pos.y(),r,WHITE);
}

void Balle::addition(FVector<float,2> vec)
{
    pos+=vec;
}

Balle::Balle()
{
    FVector<float,2> p(largeur/3,2*r);
    FVector<float,2> vit(1.5,0);
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

float prod(FVector<float, 2> a,FVector<float, 2>b)
{
    return a.x()*b.x()+a.y()*b.y();
}

void Balle::update_bas()
{
    vitesse.y()+=0.5;
}

void Balle::update_gauche()
{
    pos.x()-=10;
}

void Balle::update_droite()
{
    pos.x()+=10;
}
void Balle::rebond(int x)
{
    FVector<float, 2> ex(1,0);
    FVector<float, 2> ey(0,1);
    float a = df(x);
    FVector<float, 2> normal(-a,1);
    FVector<float,2> tangent(1,a);
    FVector<float,2> vit_(0.65*prod(prod(vitesse,tangent)*tangent-prod(vitesse,normal)*normal,ex),0.65*prod(prod(vitesse,tangent)*tangent-prod(vitesse,normal)*normal,ey));
    vitesse=vit_;

}
void Balle::rebond_supp()
{
    float vity=vitesse.y();
    vitesse.y()=-vity;
}

void Balle::rebond_gauche()
{
    float vitx=vitesse.x();
    vitesse.x()=-vitx;
}
float df(int x)
{
    return -2*M_PI*hauteur*sin(2*x*M_PI/largeur)/(8*largeur)+3*M_PI*hauteur*cos(3*x*M_PI/largeur)/(20*largeur);
}
