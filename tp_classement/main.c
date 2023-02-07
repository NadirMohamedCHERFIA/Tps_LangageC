/*
 *
 * GI - GLI - tp4
 *
 * Nom binome 1 :
 * Nom binome 2 :
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noeud
{
    char nom[32];
    int score;
    struct noeud *next;
};

typedef struct noeud Noeud; /* on definit le type "Noeud" comme etant "struct noeud" */
typedef Noeud *Liste;       /* on definit une liste comme etant un pointeur sur un noeud */

/* prototypes */
Liste ajout(char nom[], int score, Liste L);
void lister(Liste L);
int recherche(char nom[], Liste L);
Liste suppression(char nom[], Liste L);

/* definitions */
Liste ajout(char nom[], int score, Liste L)
{
    /* a completer */
    Liste current = L;
    Liste previous = L;
    Noeud* myNoeud= (Noeud*)malloc(sizeof(Noeud));
    strcpy(myNoeud->nom,nom);
    myNoeud->score = score;
    myNoeud->next = NULL;
    if(recherche(nom,L)==0){
        if(L==NULL){
            return myNoeud;
        }
        if(L->score < score ){
            myNoeud->next = L;
            return myNoeud;
        }
        while (current->score >= myNoeud->score && current->next !=NULL)
        { 
            previous = current;
            current = current->next;
        }
        previous->next = myNoeud;
        myNoeud->next = current;
        return L;
    }else{
        printf("\nLe joueur est déjà dans la liste.");
        return L;
    }
}

void lister(Liste L)
{
    int classement=1;
    if(L==NULL){
        printf("\nLa liste est vide!");
        return;
    }
    printf("\n");
    while(L!=NULL){
        printf("\nclassement: %d \tNom: %s \tScore:%d ",classement,L->nom,L->score);
        L = L->next;
        classement++;
    }
}

int recherche(char nom[], Liste L)
{
    int res = 0;
    int position=1;
    while(L){
            position++;
        if(strcmp(L->nom,nom)==0){
            res=position;
        }
        L=L->next;
    }
    return res;
}

Liste suppression(char nom[], Liste L)
{
    /* a completer */
    Liste previous = L;
    Liste current = L;
    if(recherche(nom,L)!=0){
        if(L==NULL){
            return L;
        }
        if(strcmp(L->nom,nom)==0){
            current = L->next;
            free(L);
            return current;
        }
        while(strcmp(current->nom,nom)!=0 && current->next!=NULL){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
        return L;
    }else{
        printf("\nLe nom n'exsite pas dans la liste.");
    }
}

int main()
{
    Liste L = NULL; // on cree une liste L vide
    int rang = 0;
    int choix = 0;
    char nom[32];
    int score = 0;

    while (choix < 5)
    {
        printf("\nMenu\n\n");
        printf("1 - Ajout d'un joueur\n");
        printf("2 - Lister\n");
        printf("3 - Recherche d'un joueur\n");
        printf("4 - Suppression d'un joueur\n");
        printf("5 - Fin du programme\n");
        printf("Votre choix : ");

        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Nom du joueur ? ");
            scanf("%s", nom);
            printf("Score du joueur ? ");
            scanf("%d", &score);

            L = ajout(nom, score, L);

            break;

        case 2:
            lister(L);

            break;

        case 3:
            printf("Quel joueur a rechercher : ");
            scanf("%s", nom);
            rang = recherche(nom, L);
            if (rang == 0)
                printf("Le joueur n'est pas present dans la liste.\n");
            else
                printf("nom : %s, classement : %d\n", nom, rang);

            break;

        case 4:
            printf("Quel joueur a supprimer : ");
            scanf("%s", nom);
            L = suppression(nom, L);

            break;

        default:
            printf("Bye !\n");
        }
    }

    /* Liberation memoire */
    if (L != NULL)
    {
        Noeud *p = L;
        Noeud *sup = p->next;

        while (sup != NULL)
        {
            sup = p->next;
            free(p);
            p = sup;
        }
    }

    return 0;
}
