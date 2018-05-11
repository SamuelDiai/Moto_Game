#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <queue>
#define USE_MATH_DEFINES
#include "math.h"

const int hauteur=400;
const int largeur=400;
class terrain
{
    std::vector<int> image;

public:
    terrain();
    int f(int i);
    void afficher();
    void pop_front();
    void defiler(int p);
};

int fonction(int x);
#endif // TERRAIN_H
