#include "terrain.h"
#include <ctime>

#include <string>
int pasdaff=5;

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>
using namespace Imagine;

int main()
{
    Image<Color> gameover; // Chargement de l'image "Gameover"
    load(gameover,srcPath("gameover.png"));

    int compt=0; //Initialisation d'un Compteur qui nous
                //permet de voir combien de fois la balle reste immobile

    // Initialisation
    terrain t;
    Balle b;
    openWindow(largeur,1.5*hauteur);
    t.afficher(b.getpos().x());
    double timer0=double(clock())/CLOCKS_PER_SEC;
    int score = int(b.getpos().x());

    // Début de l'algorithme
    for (int T;T<pasdaff*100000;T++)
    {
        if (int(b.getpos().x())>score) // Garde en mémoire le score(garde la distance la plus grande parcourue)
            score=int(b.getpos().x());

        double timer=-timer0+double(clock())/CLOCKS_PER_SEC;// Gestion du temps

        if ((T%pasdaff)==0)
        {
            // Affichage des objets
            noRefreshBegin();
            b.effacer_balle();
            t.afficher(b.getpos().x());
            b.afficher_balle();

            // Affichage des scores , temps , distance actuelle
            drawString(largeur-150,20,"DISTANCE :",GREEN,15);
            drawString(largeur-50,20,std::to_string(b.getpos().x()),GREEN,15);
            drawString(10,20,"TEMPS :",MAGENTA,15);
            drawString(80,20,std::to_string(timer),MAGENTA,15);
            drawString(150,50,"SCORE :",BLUE,15);
            drawString(230,50,std::to_string(score),BLUE,15);
            //Attente
            noRefreshEnd();
            milliSleep(50);
        }

        int key=Clavier();
        // Gestion du rebon sur le haut et sur le bord gauche
        if (t.contact_supp(b))
        {
            b.rebond_supp();
            b.update_air();
        }
        if (t.contact_gauche(b))
        {
            b.rebond_gauche();
            b.update_air();
        }

        // Si il n'y a pas contact on updtate la position de la balle
        if (!t.contact(b))
        {
            compt=0;
            b.update_air();
        // Gestion du clavier
            switch (key)
            {
            case 16777237:
                b.update_bas();
                break;
            default:
                break;
            }
        }
        else // Si il y a contact on fait rebondir la balle
        {
            b.rebond(b.getpos().x());
            FVector<float,2> ecart(dt*b.getvitx(),dt*b.getvity());
            if (prod(ecart,ecart)>=1e-4)// On vérifie que la balle bouge entre deux pas de temps
            {                           // Dans ce cas on update la position de la balle
                b.update_air();
            }
            else   // Sinon on incrémente la valeur du compteur
                compt+=1;
        }
        if (compt >=120) // Si le compteur est trop grand ou qu'on dépasse 30sec on stoppe l'algorithme
            break;
    }
    clearWindow(); // On affiche "Game Over"
    drawString(150,50,"SCORE :",BLUE,20);
    drawString(230,50,std::to_string(score),BLUE,20);
    display(gameover,largeur/2-120,hauteur/2);
    click();
    return 0;
}
