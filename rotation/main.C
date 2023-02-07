#include <stdio.h>
#include <stdlib.h>

int main(){
    int resultat[]={6,3,34,54,65,5,7,7,3,2,8,19};
    int taille = sizeof(resultat)/sizeof(int);
    int tmp[taille];
    tmp[0]=resultat[taille-1];
    printf("\n");
    for (int j = 0; j < taille; j++)
    {
        printf("%d ->", resultat[j]);
    }
    for(int i=0;i<taille;i++){
        tmp[i+1]=resultat[i];
    }
    printf("\n");

    for(int j=0;j<taille;j++){
        resultat[j]=tmp[j];
    }

    for(int j=0;j<taille;j++){
        printf("%d ->",resultat[j]);
    }
}