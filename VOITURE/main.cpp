#include "terrain.h"

int main()
{
    srand((unsigned int)time(0));
    terrain t;
    openWindow(largeur,hauteur);
    int x=0;
    while(true)
    {
        int p=fonction(x);
        x+=1;
        t.defiler(p);
        std::cout <<t.f(399)<<"  "<< fonction(x)<<std::endl;
        t.afficher();
        milliSleep(10);
    }
    return 0;
}
