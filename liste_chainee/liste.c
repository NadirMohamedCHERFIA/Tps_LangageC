#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Liste* emptyListe(){
    return NULL;
}

int isEmpty(Liste* l){
    return l==NULL;
}

void afficherListe(Liste* l){
    if(l==NULL){
        printf("\nLa liste est vide!");
    }
    printf("\n");
    while(l!=NULL){
        printf("%d\t",l->data);
        l=l->next;
    }
}

int listeLength(Liste*l){
    int length = 0;
    while(l!=NULL){
        length++;
        l=l->next;
    }
    return length;
}

static Noeud* createNoeud(int data){
    Noeud* myNoeud = (Noeud*)malloc(sizeof(Noeud*));
    myNoeud->data=data;
    myNoeud->next=NULL;
    return myNoeud;
}

Liste* addAt(Liste *l,int data, int position){
    Noeud* newNoeud = createNoeud(data);
    Liste* current = l;
    Liste* previous = l;
    if(position<=listeLength(l)){
        if (l == NULL)
        {
            return newNoeud;
        }
        if (position == 0)
        {
            newNoeud->next = l;
            return newNoeud;
        }
        int tmpPos = 0; // temporary position while navigating throw the liste
        while (tmpPos < position)
        {
            previous = current;
            current = current->next;
            tmpPos++;
        }
        previous->next = newNoeud;
        newNoeud->next = current;
        return l;
    }else{
        printf("Cannot add at that position");
    }
}  

Liste* removeAt(Liste* l, int position){
    Liste* temp = l;
    Liste* current = l;
    Liste* previous =l;
    if(position<=listeLength(l)){
        if(l==NULL){
            printf("\n The liste is already empty");
            return l;
        }
        if(position==0){
            current = l->next;
            free(l);
            return current;
        }
        int tempPos = 0;
        while(tempPos<position){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
        return l;

    }else{
        printf("\n Cannot remove from that position.");
    }
}

Liste* removeAll(Liste* l){
    Liste* tmp = NULL;
    while(l){
        tmp=l->next;
        free(l);
        l=tmp;
    }
    return l;
}