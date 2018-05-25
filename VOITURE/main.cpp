#include "terrain.h"

int pasdaff=5;

int main()
{

    srand((unsigned int)time(0));
    terrain t;
    Balle b;
    Balle vieille_balle = b;
    openWindow(largeur,hauteur);
    t.afficher(b.getpos().x());

    for (int T;T<pasdaff*100000;T++)
    {
        if ((T%pasdaff)==0)
        {
        noRefreshBegin();
        vieille_balle.effacer_balle();

        t.afficher(b.getpos().x());
        vieille_balle=b;
        b.afficher_balle();
        vieille_balle.afficher_balle();
        noRefreshEnd();
        milliSleep(50);
        }
        if (!t.contact_air(b))
            b.update_air();

    }
    return 0;
}
