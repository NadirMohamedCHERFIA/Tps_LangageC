#ifndef __LISTE_H__
#define __LISTE_H__

typedef struct liste{
    int data;
    struct liste * next;
}Liste,Noeud;


void afficherListe(Liste *l);

Liste* emptyListe();

int isEmpty(Liste* l);

int listeLength(Liste* l);

Liste* addAt(Liste* l, int data, int position);

Liste* removeAt(Liste*l, int position);

Liste* removeAll(Liste* l);

#endif