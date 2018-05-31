#include "terrain.h"

int pasdaff=5;

int main()
{
    srand((unsigned int)time(0));
    terrain t;
    Balle b;
    openWindow(largeur,1.5*hauteur);
    t.afficher(b.getpos().x());


    for (int T;T<pasdaff*100000;T++)
    {
        if ((T%pasdaff)==0)
        {
            noRefreshBegin();
            b.effacer_balle();
            t.afficher(b.getpos().x());
            b.afficher_balle();
            noRefreshEnd();
            milliSleep(50);
        }
        int key=Clavier();
        if (t.contact_supp(b))
        {
            b.rebond_supp();
            b.update_air();
        }
        if (!t.contact(b))
        {
            b.update_air();

            switch (key)
            {
            case 16777237:
                b.update_bas();
                break;
            case 16777234:
                b.update_gauche();
                break;
            case 16777236:
                b.update_droite();
                break;

            default:
                break;
            }
        }
        else
        {
            b.rebond(b.getpos().x());
            FVector<float,2> ecart(dt*b.getvitx(),dt*b.getvity());
            if (prod(ecart,ecart)>=1e-5)
                b.update_air();

        }
    }

std::cout<< "Game Over";


    return 0;

}
