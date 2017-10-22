#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
int main()
{
    printf("Hello world!\n");
    T_Liste *liste = creerListe(), *liste2 = creerListe(), *liste3 = creerListe();
    T_Element *recherche = NULL;

    if(insererElement(liste,"coucou") ==0) printf("insertion effectuee \n");

    if(insererElement(liste,"coucou") ==0) printf("insertion effectuée \n");
    if(insererElement(liste,"baba") ==0) printf("insertion effectuée \n");

    if(insererElement(liste,"tes") ==0) printf("insertion effectuee \n");

    if(insererElement(liste,"mot") ==0) printf("insertion effectuee \n");


    if(affichageListe(liste)==0)printf("fin affichage taille liste = %d \n",liste->taille);
    else printf("probleme affichage");



    if (supprimerElement(liste, "test")== 0) printf("Suppression réussie taille de la liste: %d \n", liste->taille);
    else printf("Impossible de supprimer l'élément \n");
    if(affichageListe(liste)==0)printf("fin affichage taille liste = %d \n",liste->taille);
    else printf("probleme affichage");


    if(insererElement(liste2,"Allo") ==0) printf("insertion effectuee \n");

    if(insererElement(liste2,"des") ==0) printf("insertion effectuée \n");

    if(insererElement(liste2,"test") ==0) printf("insertion effectuée \n");

    if(insererElement(liste2,"licorne") ==0) printf("insertion effectuée \n");



    if(insererElement(liste2,"Allo") ==0) printf("insertion effectuee \n");

    if(affichageListe(liste2)==0)printf("fin affichage taille liste = %d \n",liste2->taille);
    else printf("probleme affichage");

    liste3 = fusionnerListes(liste,liste2);

    if(affichageListe(liste3)==0)printf("fin affichage taille liste = %d \n",liste3->taille);
    else printf("probleme affichage");



/*
    liste = creerListe();

    if(insererElement(liste,"coucou") ==0) printf("insertion effectuee \n");

    if(insererElement(liste,"coucou") ==0) printf("insertion effectuée \n");
    if(insererElement(liste,"baba") ==0) printf("insertion effectuée \n");

    if(insererElement(liste,"tes") ==0) printf("insertion effectuee \n");

    if(insererElement(liste,"mot") ==0) printf("insertion effectuee \n");

    if(affichageListe(liste)==0)printf("fin affichage taille liste = %d \n",liste->taille);
    else printf("probleme affichage");


*/

    return 0;
}

