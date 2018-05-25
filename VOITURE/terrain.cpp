#include "terrain.h"

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

void terrain::afficher(int posb)
{

    clearWindow();
    for (int i=posb-largeur/3;i<posb-largeur/3+image.size();i++)
    {

        fillRect(-posb+largeur/3+i,image[i],1,1,RED);
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
    int abs = b.getpos().x();
    FVector<float,2> poscourbe(abs,fonction(abs));
    FVector<float,2> posballe(b.getpos());
    return distance(poscourbe,posballe)< b.r;
}

bool terrain::contact_air(Balle b)
{
    if (!contact(b))
        return false;
    else
    {
        float y=b.getpos().x()-dt*b.getvitx();
        float diff=fonction(y)-b.getpos().x();
        FVector<float,2> p(-1,diff);
        b.addition(p);
        if(contact(b))
        {
            return false;
        }
        else
            return true;
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
