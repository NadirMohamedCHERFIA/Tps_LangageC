#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <math.h>

#define TAILLE 6
#define VITESSE 0.12 /* en m.s-1 */

typedef struct
{
    char type[16]; /* MOVE, GRAB ou DROP */
    double dx;     /* deplacement en x (en metres) */
    double dy;     /* en y */
    double dz;     /* en z */
    double duree;  /* duree de l'action (en secondes) */
} commande;

typedef struct
{
    int t;                /* tete */
    int q;                /* queue */
    commande tab[TAILLE]; /* tableau de commandes */
    double x;             /* position x */
    double y;
    double z;
} file;

/* prototypes */
commande creer_commande();
file *creer_file(double xinit, double yinit, double zinit);
int file_pleine(file *f);
int file_vide(file *f);
void enfiler(commande c, file *f);
void defiler(file *f);
void tout_defiler(file *f);
void infos_file(file *f);


int main(){
    int choix=0;
    file* myFile = creer_file(0,0,0);
    while(choix<5){
        printf("\n1. Informations sur le file.");
        printf("\n2. Enfiler Commande.");
        printf("\n3. Defiler Commande.");
        printf("\n4. Tout defiler.");
        printf("\n5. Quitter.\n");
        scanf("%d",&choix);
        switch(choix){
            case 1:
                infos_file(myFile);
                break;
            case 2:
                enfiler(creer_commande(),myFile);
                break;
            case 3:
                defiler(myFile);
                break;
            case 4:
                tout_defiler(myFile);
                break;
            case 5:
                printf("\n BYE");
                exit(-1);
                break;
            default:
                break;
        }
    }
}

int commandeValid(char *type){
    return ((strcmp(type, "MOVE") == 0) || (strcmp(type, "DROP") == 0) || (strcmp(type, "GRAP") == 0));
}

commande creer_commande()
{
    commande myCommande ;
    myCommande.dx=0;
    myCommande.dy=0;
    myCommande.dz=0;
    strcpy(myCommande.type,"");
    while(!commandeValid(myCommande.type)){
    printf("Entrer le type de commande('MOVE','GRAP' Or 'DROP'): ");
    scanf("%s",myCommande.type);
        if(strcmp(myCommande.type,"MOVE")==0){
            printf("\nEntrer le déplacement dx : ");
            scanf("%lf",&(myCommande.dx));
            printf("\nEntrer le déplacement dy : ");
            scanf("%lf",&(myCommande.dy));
            printf("\nEntrer le déplacement dz : ");
            scanf("%lf",&(myCommande.dz));
        }
    }
    myCommande.duree = sqrt(pow(myCommande.dx, 2) + pow(myCommande.dy, 2) +pow(myCommande.dz, 2))/VITESSE;
    return myCommande;
}

file * creer_file(double xinit,double yinit,double zinit){
    file * myFile =(file*)malloc(sizeof(file));
        myFile->q=0;
        myFile->t=0;
        myFile->x=xinit;
        myFile->y=yinit;
        myFile->z=zinit;
    return myFile;
}

int file_pleine(file* f){
    return ((f->t%6)-(f->q%6)==1);
}

int file_vide(file* f){
    return (f->t%6==f->q%6);
}

void defiler(file* f){
    f->x-=f->tab[f->t].dx;
    f->y-=f->tab[f->t].dy;
    f->z-=f->tab[f->t].dz;
    f->t++;
}

void infos_file(file* f){
    int i=0,j=1;
    if(file_vide(f)){
        printf("\n La file est vide");
        return;
    }
    for(i=f->t;i<f->q;i++){
        printf("\n %d -> \t %s ",j,f->tab[i].type);
        j++;
    }
    printf("\n t:%d",f->t);
    printf("\n q:%d",f->q);
    printf("\nLe deplacement en x : %lf",f->x);
    printf("\nLe deplacement en y : %lf",f->y);
    printf("\nLe deplacement en z : %lf",f->z);
    printf("\n*******************************");
}

void enfiler(commande c,file *f){
    if(!file_pleine(f)){
        f->tab[f->q] = c;
        f->x+=c.dx;
        f->y+=c.dy;
        f->z+=c.dz;
        if(!file_pleine(f)){
            f->q++;
        }
    }else{
        printf("\n La file est pleine");
    }
}

void tout_defiler(file* f){
    while(!file_vide(f)){
        defiler(f);
    }
}