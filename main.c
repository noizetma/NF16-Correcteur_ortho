#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
int main()
{
    Liste tableau[TAILLE_MAX];
    int choix = 0,choix_liste = 0;

    Initialisation(tableau,TAILLE_MAX);

    do
    {
        printf("1. Creer une liste \n");
        printf("2. Ajouter un element dans une liste \n");
        printf("3. Supprimer un element dans une liste \n");
        printf("4. Rechercher un element dans une recherche \n");
        printf("5. Afficher les elements d'une liste\n");
        printf("6. Supprimer une liste\n");
        printf("7. Fusionner deux listes\n");
        printf("8. Quitter \n");
        printf("Entrer votre choix. \n");
        scanf("%d",&choix);

        switch (choix)
        {
            char valeur[20];
        case 1: //créer liste
		
            AffichageTableau(tableau,TAILLE_MAX);
			do{
				printf("Votre choix ? (si vous selectionnez une liste deja existante, elle sera supprimee)\n ");
				scanf("%d",&choix_liste);
			}while(choix_liste<0 || choix_liste>9);
            printf("Entrer le nom de la chaine \n");
            scanf("%s",tableau[choix_liste].nom);
            if(tableau[choix_liste].liste != NULL) supprimerListe(tableau[choix_liste].liste);
            tableau[choix_liste].liste = creerListe();
        break;
		
        case 2: //insérer liste
		
            AffichageTableau(tableau,TAILLE_MAX);
            do{
				printf("Votre choix ? \n ");
				scanf("%d",&choix_liste);
			}while(choix_liste<0 || choix_liste>9);
            viderBuffer();
            printf("Valeur a ajouter :\n");
            scanf("%s",valeur);
            if(insererElement(tableau[choix_liste].liste,valeur) == 0) printf("insertion effectuee. \n");
            else printf("insertion impossible. \n");
        break;
		
        case 3: //supprimerElement
		
            AffichageTableau(tableau,TAILLE_MAX);
            do{
				printf("Votre choix ? \n ");
				scanf("%d",&choix_liste);
			}while(choix_liste<0 || choix_liste>9);
            viderBuffer();
            printf("Valeur a supprimer :\n");
            scanf("%s",valeur);
            if(supprimerElement(tableau[choix_liste].liste,valeur) == 0) printf("suppression effectuee. \n");
            else printf("suppression impossible. \n");
        break;
		
        case 4: //rechercherElement
		
            AffichageTableau(tableau,TAILLE_MAX);
            do{
				printf("Votre choix ? \n ");
				scanf("%d",&choix_liste);
			}while(choix_liste<0 || choix_liste>9);
            viderBuffer();
            printf("Valeur a rechercher :\n");
            scanf("%s",valeur);
            if(rechercherElement(tableau[choix_liste].liste,valeur) != NULL) printf("element trouve. \n");
            else printf("element non trouve. \n");
        break;
		
        case 5: //affichageListe
		
            AffichageTableau(tableau,TAILLE_MAX);
            do{
				printf("Votre choix ? \n ");
				scanf("%d",&choix_liste);
			}while(choix_liste<0 || choix_liste>9);
            if(affichageListe(tableau[choix_liste].liste) == 0) printf("affichage termine. \n");
            else printf("affichage impossible. \n");
        break;
		
        case 6://supprimerListe
		
            AffichageTableau(tableau,TAILLE_MAX);
            do{
				printf("Votre choix ? \n ");
				scanf("%d",&choix_liste);
			}while(choix_liste<0 || choix_liste>9);
            strcpy(tableau[choix_liste].nom,"Liste inexistante");
            if(supprimerListe(tableau[choix_liste].liste) == 0) {
				
                    printf("liste supprimee. \n");
                    tableau[choix_liste].liste = NULL;
            }

            else printf("suppression impossible. \n");
        break;
		
        case 7: //fusionnerListes
		
            AffichageTableau(tableau,TAILLE_MAX);
            do{
				printf("Votre choix pour la liste 1 ? \n ");
				scanf("%d",&choix_liste);
			}while(choix_liste<0 || choix_liste>9);
            int choix_liste2 = 0,choix_fusion = 0;
            do{
				printf("Votre choix pour la liste 2 ? \n ");
				scanf("%d",&choix_liste2);
			}while(choix_liste2<0 || choix_liste2>9);
			
			do{
				printf("Votre choix pour stocker la fusion ? (si vous selectionnez une liste deja existante, elle sera supprimee, choisir une liste différente de Liste 1 et liste 2) \n");
				scanf("%d",&choix_fusion);
			}while(choix_fusion<0 || choix_fusion>9 || choix_fusion == choix_liste || choix_fusion == choix_liste2);
            if(tableau[choix_fusion].liste != NULL) supprimerListe(tableau[choix_fusion].liste);
            tableau[choix_fusion].liste = fusionnerListes(tableau[choix_liste].liste,tableau[choix_liste2].liste);
            tableau[choix_liste].liste = NULL;
            tableau[choix_liste2].liste = NULL;
            printf("Entrer nom de la liste fusion: \n");
            scanf("%s",tableau[choix_fusion].nom);
            strcpy(tableau[choix_liste].nom,"Liste inexistante");
            strcpy(tableau[choix_liste2].nom,"Liste inexistante");


        break;
		
        case 8:
            printf("Vous aller quitter l'application \n");
        break;
        default:
            printf("Cette option n'existe pas. \n");

        }
        viderBuffer();
    }while (choix != 8);
    printf("Vous quittez l'application \n");
    int i = 0;
    for(i=0;i<TAILLE_MAX;i++)
    {
        supprimerListe(tableau[i].liste);
    }


    return 0;
}

