#include "terrain.h"

terrain::terrain()
{
int p(fonction(0));
image.push_back(p);
}

void terrain::afficher()
{
    noRefreshBegin();
    clearWindow();
    for (int i=0;i<image.size();i++)
    {
        fillRect(i,image[i],1,1,RED);
    }
    noRefreshEnd();
}

void terrain::pop_front()
{
    image.erase(image.begin());
}

void terrain::defiler(int p)
{
    if (image.size()==largeur)
    {
        image.push_back(p);
        pop_front();
    }
    else
    {
        image.push_back(p);
    }
}

int fonction(int x)
{
    return hauteur/2+ cos(2*x*M_PI/largeur)*hauteur/8 + sin(3*x*M_PI/largeur)*hauteur/20;
}

int terrain::f(int i)
{
    return image[i];
}
