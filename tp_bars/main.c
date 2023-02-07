#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialisation(int *nb_bat, int *jo);
void jeu(int *jo, int *nb_bat);
void machine_joue(int *nb_bat);
void utilisateur_joue(int *nb_bat);
void changer_joueur(int *jo);
void aleat(int *res);
void afficher_batons(int* nb_bat);
int jouerValid(int *jo);
int removeisValid(int remove);

int main(){
    int jo,nb_bat;
    initialisation(&nb_bat,&jo);
    while(nb_bat>0){
        jeu(&jo,&nb_bat);
    }
    if(jo==1){
        printf("\n*****************");
        printf("\n*Vous avez perdue*");
        printf("\n******************");
    }if(jo==2){
        printf("\n*****************");
        printf("\n*Vous avez gagne*");
        printf("\n*****************");
    }
}

void aleat(int *res){
    int graine = time(NULL);
    srand(graine);
    *res = (rand()%2 )+1;
}

void initialisation(int* nb_bat, int *jo){
    printf("\n Entrer le nombre des batons:");
    scanf("%d",nb_bat);
    aleat(jo);
}

int removeIsValid(int removed){
    return (removed>=1 && removed<=3);
}

int joueurValid(int *jo){
    return (*jo==1 || *jo==2);
}

void utilisateur_joue(int* nb_bat){
    int removed=0;
    printf("\nUtilisateur joue:");
    while(!removeIsValid(removed)){
        printf("\nEntrer le nombre de batons à retirer: ");
        scanf("%d",&removed);
    }
    *nb_bat -= removed;
}

void machine_joue(int* nb_bat){
    printf("\nmachine joue:");
    int mod;
    srand(time(NULL));
    mod = *nb_bat%4;
    switch(mod){
        case 0:
            *nb_bat-=3;
            break;
        case 1:
            *nb_bat-= ((rand()%2)+1);
            break;
        case 2:
            *nb_bat-=1;
            break;
        case 3:
            *nb_bat-=2;
            break;
        default:
            printf("\n Error");
            break;
    }
}

void changer_joueur(int*jo){
    if(joueurValid(jo)){
        if(*jo==1){
            *jo=2;
        }else if(*jo==2){
            *jo=1;
        }
    }else{
        printf("\n Joueur non valide.");
    }
}

void jeu(int *jo,int *nb_bat){
    if(*nb_bat>0){
        if(*jo==1){
            utilisateur_joue(nb_bat);
        }if(*jo==2){
            machine_joue(nb_bat);
        }
        if(*nb_bat>0){
            afficher_batons(nb_bat);
            changer_joueur(jo);
        }
    }
}

void afficher_batons(int *nb_bat){
    int i = 0;
    printf("\n  Il reste %d batons: ", *nb_bat);
    for(int i=0;i<*nb_bat;i++){
        printf("|");
    }
}