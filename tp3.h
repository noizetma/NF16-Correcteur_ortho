#ifndef DEF_TP3
#define DEF_TP3

typedef struct Element T_Element;
struct Element{
char valeur[20];
T_Element *suivant, *precedent;
};

typedef struct Liste T_Liste;
struct Liste{
int taille;
T_Element *tete,*queue;
};

T_Element *creerElement(char * val);
T_Liste *creerListe();

int insererElement(T_Liste *list, char *val);
int affichageListe(T_Liste *list);
T_Element *rechercherElement(T_Liste *list, char *val);
int supprimerElement(T_Liste *list, char *val);





#endif // DEF_TP3
