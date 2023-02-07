/* GLI - Examen de TP 2020-2021

NOM :
PRENOM :

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define emp printf("Empiler");
#define dep printf("Depiler");

#define TAILLE 64 // Taille de la pile, moitie de la taille du texte

struct pile
{                     // La structure de pile
    char Tab[TAILLE]; // Un tableau
    int t;            // Un indice de tete
};

typedef struct pile Pile; // On redefinit le type "struct pile" comme : "Pile"

int est_vide(Pile *P);         // A ecrire
int est_pleine(Pile *P);       // A ecrire
void empiler(char c, Pile *P); // A ecrire
char depiler(Pile *P);         // A ecrire

int main()
{
    char texte[TAILLE * 2 + 1]; // Le texte à vérifier
    int res = 1;int d =0,e=0;
    Pile* p =(pile*)malloc(sizeof(pile));
    p->t=0;
    printf("Taper un texte :\n");
    scanf("%s", texte); // Saisie du texte par l'utilisateur
    // A completer //
    int i = 0;char c;
    for(i=0;i<strlen(texte);i++){
    c=texte[i];
        if (c == '{' || c == '(' || c == '['){
            // emp
            empiler(c,p);
            e++;

        }
        else if(c=='}'){
            d++;
            if(depiler(p)!='{'){
                printf("\nPhrase mal parenthésé.");
                return 0;
            }
        }
        else if(c==')'){
            d++;
            if (depiler(p) != '(')
            {
                printf("\nPhrase mal parenthésé.");
                return 0;
            }
        }
        else if(c==']'){
            d++;
            if (depiler(p) != '[')
            {
                printf("\nPhrase mal parenthésé.");
                return 0;
            }
        }
    }
    printf("\ne: %d\td: %d",e,d);
    return 0;
}

int est_vide(pile *p){
    if(p->t==0){
        return 1;
    }
        return 0;
}
int est_pleine(pile *p){
    if(p->t==TAILLE){
        return 1;
    }
    return 0;
}

void empiler(char c,Pile *p){
    if(!est_pleine(p)){
        p->Tab[p->t]=c;
        (p->t)++;
    }
}
char depiler(Pile *p){
    int lettre;
    if(!est_vide(p)){
        lettre = p->Tab[p->t-1];
        p->t--;
    }
    return lettre;
}