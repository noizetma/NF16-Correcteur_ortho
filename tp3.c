#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

void Initialisation (Liste tableau[], int taille)
{
    int i = 0;
    for(i=0;i<taille;i++)
    {
        strcpy(tableau[i].nom,"Liste inexistante");
        (tableau[i]).liste = NULL;
    }
}

void AffichageTableau(Liste tableau[],int taille)
{
    int i = 0;
    for(i = 0;i<taille;i++)
    {
        printf("%d. %s \n",i,tableau[i].nom);
    }
}

void viderBuffer()
{
    char c = 0;
    while(c!= '\n' && c != EOF)
        c= getchar();
}

T_Element *creerElement(char *val)
{
    T_Element *nouveau = malloc(sizeof *nouveau);
    //if (nouveau == NULL|| strlen(val)>20) exit(0);
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

int insererDebutListe(T_Liste *list, char *val)
{
    T_Element *nouveau = creerElement(val);
    if(list == NULL) return -1;
    if(list->queue == NULL)//liste vide
    {
        list->queue = nouveau;
        list->tete = nouveau;

    }
    else
    {
        if(strcmp(nouveau->valeur,list->tete->valeur)== 0) return -1;
        list->tete->precedent = nouveau;
        nouveau->suivant = list->tete;
        list->tete = nouveau;
    }
    list->taille += 1;
    return 0;
}

int insererFinListe(T_Liste *list, char *val)
{
    T_Element *nouveau = creerElement(val);
    if(list == NULL) return -1;

    if(list->queue == NULL)//liste vide
    {
        list->queue = nouveau;
        list->tete = nouveau;

    }
    else
    {
        if(strcmp(nouveau->valeur,list->queue->valeur)== 0) return -1;
        list->queue->suivant = nouveau;
        nouveau->precedent = list->queue;
        list->queue = nouveau;
    }
    list->taille += 1;
    return 0;

}

int insererElement(T_Liste *list, char *val)
{

    if(list == NULL) return -1;
    if(list->queue == NULL || strcmp(val,list->tete->valeur)<= 0)
    {
        return insererDebutListe(list,val);
    }
    else if (strcmp(val,list->queue->valeur)>= 0)
    {
        return insererFinListe(list,val);
    }
    else
    {
        T_Element *nouveau = creerElement(val);
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
            list->taille += 1;
            return 0;



    }



}

int affichageListe(T_Liste *list)
{
    if(list == NULL || list->queue == NULL)  return -1;
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



    free(list); //je ne sais pas si a marche
    list->taille = 0;
    list->tete = NULL;
    list->queue = NULL;


    return 0;
}

T_Liste *fusionnerListes(T_Liste *list1, T_Liste *list2)
{
    T_Liste *fusion = creerListe();
    if (fusion == NULL) exit(0);
    if (list1 == NULL && list2 == NULL) return  NULL;
    if(list1 == NULL || list1->queue == NULL)
    {
        fusion->queue = list2->queue;
        fusion->tete = list2->tete;
        fusion->taille = list2->taille;
        free(list2);
        return fusion;
    }
    else if (list2 == NULL || list2->queue == NULL)
    {
        fusion->queue = list1->queue;
        fusion->tete = list1->tete;
        fusion->taille = list1->taille;
        free(list1);
        return fusion;
    }
    else
    {
        T_Element *pointeur1 = list1->tete, *pointeur2 = list2->tete;
        while (pointeur1 != NULL || pointeur2 != NULL)
        {
            if( pointeur1 != NULL && pointeur2 != NULL && strcmp(pointeur1->valeur,pointeur2->valeur)==0)
            {
                insererFinListe(fusion,pointeur1->valeur);
                pointeur1=pointeur1->suivant;
                pointeur2=pointeur2->suivant;

            }else if(pointeur1 != NULL && (pointeur2 == NULL || strcmp(pointeur1->valeur,pointeur2->valeur)< 0))
            {
                insererFinListe(fusion,pointeur1->valeur);
                pointeur1=pointeur1->suivant;


            }else
            {
                insererFinListe(fusion,pointeur2->valeur);
                pointeur2=pointeur2->suivant;

            }


        }
        supprimerListe(list1);
        supprimerListe(list2);
        return fusion;
    }

}




