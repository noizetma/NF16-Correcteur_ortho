#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

void Initialisation (Liste tableau[], int taille) //initialisation du tableau de listes chaînées
{
    int i = 0;
    for(i=0;i<taille;i++)
    {
        strcpy(tableau[i].nom,"Liste inexistante");
        (tableau[i]).liste = NULL;
    }
}

void AffichageTableau(Liste tableau[],int taille) //affichage des titres des listes (utilisée pour choisir la liste à utiliser)
{
    int i = 0;
    for(i = 0;i<taille;i++)
    {
        printf("%d. %s \n",i,tableau[i].nom);
    }
}

void viderBuffer() //lors d'un scan le caractère \n est stocké dans le buffer et tous les caractères dépassant la taille limite de la chaîne sont également stockés dans le buffer d'où la nécessité de le vider
{
    char c = 0;
    while(c!= '\n' && c != EOF)
        c= getchar();
}

T_Element *creerElement(char *val)
{
    T_Element *nouveau = malloc(sizeof *nouveau);
    if (nouveau == NULL) exit(0);
    nouveau->precedent = NULL;
    nouveau->suivant = NULL;
    strcpy(nouveau->valeur,val); //affectation de val à nouveau->valeur

    return nouveau;
}

T_Liste *creerListe() //initialisation de la liste
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
    if(list == NULL) return -1; // si la liste n'existe pas impossible d'insérer
    T_Element *nouveau = creerElement(val);
    if(list->queue == NULL) //Si list->queue NULL alors liste vide donc on affecte nouveau à list->queue et à list->tete
    {
        list->queue = nouveau;
        list->tete = nouveau;

    }
    else //sinon liste non vide -> insertion en début de liste
    {
        if(strcmp(nouveau->valeur,list->tete->valeur)== 0) return -1;
        list->tete->precedent = nouveau;
        nouveau->suivant = list->tete;
        list->tete = nouveau;
    }
    list->taille += 1; //incrémentation de la taille
    return 0;
}

int insererFinListe(T_Liste *list, char *val)
{
    if(list == NULL) return -1; // si la liste n'existe pas impossible d'insérer
    T_Element *nouveau = creerElement(val);


    if(list->queue == NULL)//Si list->queue NULL alors liste vide donc on affecte nouveau à list->queue et à list->tete
    {
        list->queue = nouveau;
        list->tete = nouveau;

    }
    else //liste non vide -> insertion en fin de liste
    {
        if(strcmp(nouveau->valeur,list->queue->valeur)== 0) return -1;
        list->queue->suivant = nouveau;
        nouveau->precedent = list->queue;
        list->queue = nouveau;
    }
    list->taille += 1; //incrémentation de la taille
    return 0;

}

int insererElement(T_Liste *list, char *val)
{

    if(list == NULL) return -1; // si la liste n'existe pas impossible d'insérer
    if(list->queue == NULL || strcmp(val,list->tete->valeur)<= 0) //si la liste est vide ou si le nouveau élément est plus petit que la tete de la liste alors insertion début de liste
    {
        return insererDebutListe(list,val);
    }
    else if (strcmp(val,list->queue->valeur)>= 0) //si la liste est vide ou si le nouveau élément est plus petit que la tete de la liste alors insertion début de liste
    {
        return insererFinListe(list,val);
    }
    else //liste non vide et nouveau élément supérieur strictement à la tete et inférieur strictement à la queue
    {

        T_Element *nouveau = creerElement(val); //initialisation du nouveau élément
        T_Element *actuel = list->tete->suivant, *precede = list->tete; //on commencer à parcourir la liste à partir du deuxième élément (list->tete->suivant) car le nouveau élément est supérieur strictement à la tete

        while(actuel != NULL && strcmp(nouveau->valeur,actuel->valeur)>=0) //on parcourt la liste pour savoir où insérer l'élément
        {

            if(strcmp(nouveau->valeur,actuel->valeur)==0) // si l'élément est déjà présent on annule l'insertion
            {
                free(nouveau);
                return -1;
            }
            precede = actuel;
            actuel = actuel->suivant;
        }

            nouveau->suivant = actuel;
            nouveau->precedent = precede;
            precede->suivant = nouveau; // if (precede != NULL) pas utile car precede est forcément non nul car le seul élément qui n'a pas de précédent est la tête or le nouvel élément est strictement supérieure à la tête
             actuel ->precedent = nouveau; //if (actuel != NULL) pas utile car actuel est forcément non nul car le nouvel élément est strictement inférieur à la queue

            list->taille += 1; //incrémentation de la taille
            return 0;



    }



}


int affichageListe(T_Liste *list)
{
    if(list == NULL || list->queue == NULL)  return -1; // si la liste est NULL ou si la liste est vide on ne peut pas afficher la liste
    T_Element *actuel = list->tete;
    do
    {
        printf("%s \n",actuel->valeur);
        actuel = actuel -> suivant;
    }while(actuel != NULL); // on parcourt et affiche la totalité de la liste
    return 0;
}

T_Element *rechercherElement(T_Liste *list, char *val)
{
    if(list == NULL || list->queue == NULL)  return NULL; // si la liste est NULL ou si la liste est vide on ne peut pas rechercher d'élément
    T_Element *actuel = list->tete;
    while (actuel != NULL && strcmp(actuel->valeur,val) < 0) //on parcourt la liste jusqu'à trouvé un élement supérieur ou égal à l'élément recherché
    {
        actuel = actuel->suivant;
    }
    if (actuel== NULL || strcmp(actuel->valeur,val) > 0) return NULL; // si le premier élément supérieur ou égal à l'élément cherché n'est pas égal à l'élément recherché ou si l'élément recherché n'existe pas on renvoie NULL
    return actuel;
}

int supprimerElement(T_Liste *list, char *val)
{
    if(list == NULL || list->queue == NULL) return -1; // si la liste est NULL ou si la liste est vide on ne peut pas supprimer d'élément

    T_Element *elementASup = rechercherElement(list,val); //on recherche l'élément
    if (elementASup == NULL) return -1; // si on n'a pas trouvé l'élément on annule la suppression

    if(elementASup->precedent != NULL) elementASup->precedent->suivant = elementASup->suivant; // si l'élément admet un précédent on modifie le suivant du précédent
    else list->tete = elementASup->suivant; //sinon on modifie la tete car la tete est le seul element qui n'a pas de précédent

    if(elementASup->suivant != NULL) elementASup->suivant->precedent = elementASup->precedent;// si l'élément admet un suivant on modifie le précédent du suivant
    else list->queue = elementASup->precedent;//sinon on modifie la queue car la queue est le seul element qui n'a pas de suivant
    free(elementASup);
    list->taille -=1; // décrémentation de la taille
    return 0;
}

int supprimerListe(T_Liste *list)
{
    if(list == NULL) return -1; //si la liste n'existe pas (NULL) on annule la suppression
    T_Element *actuel = list->tete;
    while (actuel != NULL) //on parcourt la liste et on supprime chaque élément qu'on rencontre et on passe à l'élément suivant
    {
        /* on ne réutilise pas la fonction supprimerElement afin de ne pas augmenter la complexité car supprimerElement fait appel à la fonction recherche qui est en O(n)
        donc on aurait une complexité en O(n²) or ici on supprime les éléments un par un sans se préoccuper de leur position dans la liste et
         il n'y a pas besoin d'adapter les valeurs des pointeurs au cours de la suppression de la liste comme le fait la fonction supprimerElement*/

        T_Element *elementASupprimer = actuel;
        actuel = actuel ->suivant;
        free(elementASupprimer);
        printf("Element supprime \n");
    }



    free(list); // On libère l'espace utilisé par la structure list qui nous permettait de "contrôler" notre liste




    return 0;
}

T_Liste *fusionnerListes(T_Liste *list1, T_Liste *list2)
{

    if (list1 == NULL && list2 == NULL) return  NULL; // si les 2 listes sont NULL on renvoie NULL
    T_Liste *fusion = creerListe();
    if(list1 == NULL || list1->queue == NULL) // si la première liste est vide on copie toutes les valeurs de list2 dans fusion (on "déplace" la liste de list2 vers fusion)
    {
        fusion->queue = list2->queue;
        fusion->tete = list2->tete;
        fusion->taille = list2->taille;
        free(list2); //on ne supprime pas la totalité de la liste à l'aide de supprimerListe car list2 et fusion ont les mêmes éléments. Il suffit de libérer l'espace alloué à list2
        return fusion;
    }
    else if (list2 == NULL || list2->queue == NULL) // sinon si la deuxième liste est vide on copie toutes les valeurs de list1 dans fusion (on "déplace" la liste de list1 vers fusion)
    {
        fusion->queue = list1->queue;
        fusion->tete = list1->tete;
        fusion->taille = list1->taille;
        free(list1); //on ne supprime pas la totalité de la liste à l'aide de supprimerListe car list1 et fusion ont les mêmes éléments. Il suffit de libérer l'espace alloué à list1
        return fusion;
    }
    else //sinon si list1 et list2 sont non vides
    {
        T_Element *pointeur1 = list1->tete, *pointeur2 = list2->tete;
        while (pointeur1 != NULL || pointeur2 != NULL) //on parcourt la totalité des 2 listes
        {
            /*Nous allons insérer tous les éléments des 2 listes dans un ordre croissant,
             les 2 listes sont elles mêmes triées */

            if( pointeur1 != NULL && pointeur2 != NULL && strcmp(pointeur1->valeur,pointeur2->valeur)==0) // si les éléments sont égaux
            {
                insererFinListe(fusion,pointeur1->valeur); // on insère une seule fois l'élément car on ne veux pas 2 fois le même élément dans la liste
                pointeur1=pointeur1->suivant;
                pointeur2=pointeur2->suivant;// on passe aux éléments suivants

            }else if(pointeur1 != NULL && (pointeur2 == NULL || strcmp(pointeur1->valeur,pointeur2->valeur)< 0))


            /* si le pointeur1 qui est un élément de la list1 est non nul
            ET que la list2 ne contient plus d'élément ou que la valeur de pointeur 1
            est inférieur à la valeur de pointeur2 */

            {
                insererFinListe(fusion,pointeur1->valeur); //insertion de pointeur1->valeur
                pointeur1=pointeur1->suivant; //passage à l'élément suivant de liste 1


            }

            else
            /* si le pointeur2 qui est un élément de la list2 est non nul
            ET que la list1 ne contient plus d'élément ou que la valeur de pointeur2
            est inférieur à la valeur de pointeur1 */

            {
                insererFinListe(fusion,pointeur2->valeur); //insertion de pointeur2->valeur
                pointeur2=pointeur2->suivant;//passage à l'élément suivant de liste 2

            }


        }
        //suppression des 2 listes
        supprimerListe(list1);
        supprimerListe(list2);
        return fusion;
    }

}




