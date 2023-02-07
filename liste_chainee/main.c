#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(){
    int choix;
    int data, position;
    Liste* myListe=emptyListe();
    while(1){
        fflush(stdin);
        printf("\nSelect your choice:");
        printf("\n1-Affihcer la liste");
        printf("\n2-Add to the liste");
        printf("\n3-Remove from the liste");
        printf("\n4-Remove all the liste");
        printf("\n5-To exit\n");
        scanf("%d",&choix);
        switch(choix){
            case 1:
                afficherListe(myListe);
                break;
            case 2:
                printf("\nEnter the data: ");
                fflush(stdin);
                scanf("%d",&data);
                printf("\nEnter the position: ");
                scanf("%d",&position);
                myListe = addAt(myListe,data,position);
                break;
            case 3:
                fflush(stdin);
                printf("\nEnter the position: ");
                scanf("%d",&position);
                myListe = removeAt(myListe,position);
                break;
            case 4:
                myListe = removeAll(myListe);
                break;
            case 5:
                exit(-1);
            default:
                break;
        }
    }
}