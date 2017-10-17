#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
int main()
{
    printf("Hello world!\n");
    T_Liste *liste = creerListe();
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


    if(supprimerListe(liste)== 0) printf("liste supprimée \n");
    else ("impossible de supprimer la liste \n");

    if(liste == NULL) printf("liste vraiment supprimée");
    else printf("pas vraiment %d",liste->tete->valeur);




    return 0;
}

