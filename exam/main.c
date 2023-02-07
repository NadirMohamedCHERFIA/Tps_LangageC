#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 10

typedef struct
{
    char nom[31];
    char prenom[31];
    char tel[11];
} personne;

typedef struct {
    personne contacts[TAILLE_MAX];
    int taille;
}annuaire;

annuaire* cree_annuaire(){
    annuaire* myAnnuaire = (annuaire*)malloc(sizeof(annuaire));
    myAnnuaire->taille = 0;
    return myAnnuaire;
}

personne saisie_personne(){
    personne thisPersonne;
    printf("\nEntrer le nom de personne : ");
    fflush(stdin);
    scanf("%s",&(thisPersonne.nom));
    printf("\nEntrer le prenom de personne : ");
    fflush(stdin);
    scanf("%s",&(thisPersonne.prenom));
    printf("\nEntrer le numéro de téléphone : ");
    fflush(stdin);
    scanf("%s",&(thisPersonne.tel));
    return thisPersonne;
}

void ajout_annuaire(personne p,annuaire *a){
        a->contacts[a->taille] = p;
        a->taille+=1;
}

void affiche_personne(personne p){
    printf("\n Nom : %s",p.nom);
    printf("\n Prenom : %s",p.prenom);
    printf("\n Telephone : %s \n",p.tel);
}

void afficher_annuaire(annuaire * a){
    int i=0;
    for(i = 0;i<(a->taille);i++){
        printf("\n %d.",i+1);
        affiche_personne(a->contacts[i]);
    }
}

void recherche(char lettre,annuaire *a){
    int i =0;
    for(i=0;i<(a->taille);i++){
        if(a->contacts[i].nom[0] == lettre){
            affiche_personne(a->contacts[i]);
            return;
        }
    }
    printf("\nY'a aucune personne qui commence par le lettre %c",lettre);
} 
int main(){

    int choix = 0;                char lettre;
    annuaire* a = cree_annuaire();
    while(1){
        printf("\n1.Ajout d'une personne dans l'aanuaire.");
        printf("\n2.Afiichage de l'annuaire.");
        printf("\n3.Recherche d'un personne dans l'annuaire.");
        printf("\n4.Quitter.\n");
        scanf("%d",&choix);
        personne newPersonne;
        switch(choix){
            case 1:
            newPersonne = saisie_personne();
                if(a->taille == TAILLE_MAX){
                    printf("\nL'annuaire est plein.");
                    break;
                }else{
                    ajout_annuaire(newPersonne,a);
                    break;
                }
            case 2:
                afficher_annuaire(a);
                break;
            case 3:
                printf("\nEntrer le premier caractére du nom de personne à rechercher : ");
                fflush(stdin);
                scanf("%c",&lettre);
                recherche(lettre,a);
                break;
            case 4 : 
                exit(-1);
                break;
            default :
                break;
        }
    }

}