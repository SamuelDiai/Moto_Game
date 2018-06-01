#include "terrain.h"
#include <Imagine/Images.h>
using namespace Imagine;
float distance(FVector<float,2> a ,FVector<float,2> b)
{
    return sqrt((a.x()-b.x())*(a.x()-b.x())+(a.y()-b.y())*(a.y()-b.y()));
}

terrain::terrain()
{
    for (int j=0;j<6*largeur;j++)
    {
        int p(fonction(j));
        image.push_back(p);
    }
}

void terrain::afficher(int posb,Image<Color> fond)
{

    clearWindow();
    display(fond);
    for (int i=posb-largeur/3;i<posb-largeur/3+image.size()/6;i++)
    {

        fillRect(-posb+largeur/3+i,hauteur/3+image[i%image.size()],1,hauteur,RED);
    }

}

void terrain::pop_front()
{
    image.erase(image.begin());
}

void terrain::defiler(int p)
{

    if (image.size()>largeur)
    {
        image.push_back(p);
        pop_front();
    }
    else
    {
        image.push_back(p);
    }
}

bool terrain::contact(Balle b)
{

    int abs = b.getpos().x()+dt*b.getvitx();
    FVector<float,2> poscourbe(abs,fonction(abs));
    FVector<float,2> deplacement(dt*b.getvitx(),dt*b.getvity());
    FVector<float,2> posballe(b.getpos()+deplacement);
    return (distance(poscourbe,posballe)< b.r && (b.getpos().y() < fonction(abs)));
}


bool terrain::contact_supp(Balle b)
{
    return b.getpos().y()+dt*b.getvity()+hauteur/3<=b.r;
}


bool terrain::contact_gauche(Balle b)
{
    return b.getpos().x()+dt*b.getvitx()<=largeur/3;
}


float fonction(int x)
{
    return hauteur/2+ cos(2*x*M_PI/largeur)*hauteur/8 + sin(3*x*M_PI/largeur)*hauteur/20;
}



int terrain::f(int i)
{
    return image[i];
}



int Clavier()
{
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
        {
            return e.key;
        }
    } while (e.type!=EVT_NONE);
    return 0;
}
