#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

T_Element *creerElement(char *val)
{
    T_Element *nouveau = malloc(sizeof *nouveau);
    if (nouveau == NULL|| strlen(val)>20) exit(0);
    nouveau->precedent = NULL;
    nouveau->suivant = NULL;
    strcpy(nouveau->valeur,val);

    return nouveau;
}

T_Liste *creerListe()
{
    T_Liste *newList = malloc(sizeof *newList);
    if (newList == NULL) exit(0);
    newList->taille = 0;
    newList->tete= NULL;
    newList->queue = NULL;

    return newList;
}



int insererElement(T_Liste *list, char *val)
{
    T_Element *nouveau = creerElement(val);
    if(list == NULL) return -1;
    if(list->queue == NULL)//liste vide
    {
        list->queue = nouveau;
        list->tete = nouveau;

    }
    else if (strcmp(nouveau->valeur,list->tete->valeur)<= 0)
    {
        if(strcmp(nouveau->valeur,list->tete->valeur)== 0) return -1;
        list->tete->precedent = nouveau;
        nouveau->suivant = list->tete;
        list->tete = nouveau;
    }
    else if (strcmp(nouveau->valeur,list->queue->valeur)>= 0)
    {
        if(strcmp(nouveau->valeur,list->queue->valeur)== 0) return -1;
        list->queue->suivant = nouveau;
        nouveau->precedent = list->queue;
        list->queue = nouveau;
    }
    else
    {
        T_Element *actuel = list->tete->suivant, *precede = NULL;
        while(actuel != NULL && strcmp(nouveau->valeur,actuel->valeur)>=0)
        {

            if(strcmp(nouveau->valeur,actuel->valeur)==0) return -1;
            precede = actuel;
            actuel = actuel->suivant;
        }

            nouveau->suivant = actuel;
            nouveau->precedent = precede;
            precede->suivant = nouveau;
            actuel ->precedent = nouveau;




    }
    list->taille += 1;
    return 0;

}

int affichageListe(T_Liste *list)
{
    if(list == NULL) return -1;
    T_Element *actuel = list->tete;
    do
    {
        printf("%s \n",actuel->valeur);
        actuel = actuel -> suivant;
    }while(actuel != NULL);
    return 0;
}

T_Element *rechercherElement(T_Liste *list, char *val)
{
    T_Element *actuel = list->tete;
    while (actuel != NULL && strcmp(actuel->valeur,val) != 0)
    {
        actuel = actuel->suivant;
    }
    return actuel;
}

int supprimerElement(T_Liste *list, char *val)
{
    if(list == NULL) return -1;
    T_Element *elementASup = rechercherElement(list,val);
    if (elementASup == NULL) return -1;

    if(elementASup->precedent != NULL) elementASup->precedent->suivant = elementASup->suivant;
    else list->tete = elementASup->suivant;

    if(elementASup->suivant != NULL) elementASup->suivant->precedent = elementASup->precedent;
    else list->queue = elementASup->precedent;

    free(elementASup);
    list->taille -=1;
    return 0;
}

int supprimerListe(T_Liste *list)
{
    if(list == NULL) return -1;
    T_Element *actuel = list->tete;
    while (actuel != NULL)
    {

        T_Element *elementASupprimer = actuel;
        actuel = actuel ->suivant;
        free(elementASupprimer);
        printf("Element supprime \n");
    }


    list->taille = 0;
    list->tete = NULL;
    list->queue = NULL;
    free(list); //je ne sais pas si ça marche
    list = NULL; //ça ne marche pas


    return 0;
}




