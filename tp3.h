#ifndef DEF_TP3
#define DEF_TP3
#define TAILLE_MAX 10 //nombre de listes
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


typedef struct TableauListe Liste; //structure de gestion de nos listes chaînées
struct TableauListe{

char nom[255]; // titre de la liste afin de différencier les listes
T_Liste *liste;

};
//liste des fonctions

//fonctions Pour la gestion des interactions avec l'utilisateur
void Initialisation (Liste tableau[], int taille);
void AffichageTableau (Liste tableau[], int taille);
void viderBuffer();

//création des éléments et des listes
T_Element *creerElement(char * val);
T_Liste *creerListe();

//fonctions pour interagir avec les listes
int insererDebutListe(T_Liste *list, char *val);
int insererFinListe(T_Liste *list, char *val);
int insererElement(T_Liste *list, char *val);
int affichageListe(T_Liste *list);
T_Element *rechercherElement(T_Liste *list, char *val);
int supprimerElement(T_Liste *list, char *val);
T_Liste *fusionnerListes(T_Liste *list1, T_Liste *list2);





#endif // DEF_TP3
