#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAILLE_MAX 35

/* prototypes */

/* Initialisation de la chaine de caracteres avec la taille du mot secret et un caractere particulier */
void init_mot_devine(char mot[], int taille);

/* Dialogue avec le joueur pour recuperer une lettre */
char demande_lettre();

/* Rechercher la lettre dans le mot secret */
int cherche_lettre(char mot_sec[], char mot[], char lettre, int taille);

/* Recuperation d'un mot dans une chaine */
void nouveau_mot(char mot_sec[]);

void lettres_deja_cherche(char liste[],int limit){
    int i=0;
    printf("\n les lettres deja cherche: ");
    for(i=0;i<limit;i++){
        printf("%c ->",liste[i]);
        i++;
    }
}
/* definitions */

int main()
{
    char motSecret[TAILLE_MAX];
    char mot_devine[TAILLE_MAX];
    int difficult;
    int graine=time(NULL);
    int taille;
    char c;
    srand(graine);
    while(1){
        while(difficult<5 || difficult>11){
            printf("\nEntrer le niveau de diffuculté:");
            scanf("%d",&difficult);
        }
        break;
    }
    nouveau_mot(motSecret);
    taille = strlen(motSecret);
    init_mot_devine(mot_devine,taille);
    printf("\n%s",motSecret);
    char liste[difficult];
    int i=0;
    while (difficult != 0 && strcmp(motSecret, mot_devine) != 0)
    {
        printf("\n*******************************************");
        printf("\n le nombre d'essais restent : %d",difficult);
        c=demande_lettre();
        liste[i]=c;
        i++;
        lettres_deja_cherche(liste,i);
        if(cherche_lettre(motSecret,mot_devine,c,taille)==0){
            difficult--;
        }
        printf("\nmot à deviner : %s",mot_devine);
    }
    if(difficult!=0){
        printf("\nvous avez gagne");
    }else{
        printf("\nVous avez perdue");
    }
    /* A completer */
    return 0;
}

void init_mot_devine(char mot[], int taille)
{
    int i=0;
    for(i=0;i<taille;i++){
        mot[i]='*';
    }
    mot[taille]='\0';
}
char demande_lettre()
{
    char c = 0;
    while(!((c>=65 && c<=90) || (c>=97 && c<=122))){
    printf("\nEntrer une lettre: ");
    fflush(stdin);
    scanf("%c",&c);
    }
    if (((c >= 97 && c <= 122))){
        c = c - 32;
    }
    /* A completer */
    return c;
}

int cherche_lettre(char mot_sec[], char mot[], char lettre, int taille)
{
    int res = 0;
    int i=0;
    /* A completer */
    for(i=0;i<taille;i++){
        if(mot_sec[i]==lettre){
            mot[i]=lettre;
            res++;
        }
    }
    return res;
}

void nouveau_mot(char mot_sec[])
{
    int nb_alea, j = 0, c;
    FILE *fichier = NULL;
    fichier = fopen("liste.txt", "r");

    if (fichier != NULL)
    {
        nb_alea = rand() % 78855;
        rewind(fichier);

        while ((c = fgetc(fichier)) != EOF)
        {
            if (c == '\n')
            {
                j++;
                if (j == nb_alea)
                {
                    fgets(mot_sec, TAILLE_MAX, fichier);
                }
            }
        }
        mot_sec[strlen(mot_sec) - 1] = 0;
    }

    else
        printf("Erreur d'ouverture de fichier\n");
}
