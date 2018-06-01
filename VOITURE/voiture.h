#ifndef VOITURE_H
#define VOITURE_H
 #include <Imagine/Graphics.h>
using namespace Imagine;

const float dt=1;
const int hauteur=400;
const int largeur=400;

class Balle
{
FVector<float,2> pos;
FVector<float,2> vitesse;

public :
int r = 4;
Balle();
void effacer_balle();
void update_air();
void afficher_balle();
FVector<float,2> getpos();
void addition(FVector<float,2> vec);
int getvitx();
int getvity();
void rebond(int x);
void rebond_supp();
void rebond_gauche();
void update_bas();
void update_gauche();
void update_droite();
};
float df(int x);
float prod(FVector<float, 2> a,FVector<float, 2>b);
#endif // VOITURE_H
