#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <Imagine/Graphics.h>
using namespace Imagine;
#include "voiture.h"

#define USE_MATH_DEFINES
#include "math.h"


float distance(FVector<float,2> a ,FVector<float,2> b);
class terrain
{
    std::vector<int> image;

public:
    terrain();
    int f(int i);
    void afficher(int posb);
    void pop_front();
    void defiler(int p);
    bool contact(Balle b);
    bool contact_air(Balle b);
    bool contact_supp(Balle b);
    bool contact_gauche(Balle b);

};

float fonction(int x);
int Clavier() ;
#endif // TERRAIN_H
