#include <stdio.h>
#include<stdlib.h>

void afficher_tableau(int *tab,int taille){
    int i=0;
    // int taille =sizeof(tab)/sizeof(int);
    printf("\n taille de tab3: %d \n",taille);
    for(i=0;i<taille;i++){
        printf("%d ->",*(tab+i));
    }
}

int main(){
    int tab[]={1,2,3,4,5};
    int tab2[]={2,4,5,6,7,8,10};
    int taille = sizeof(tab)/sizeof(int);
    int taille2 = sizeof(tab2)/sizeof(int);
    int taille_total=taille+taille2;
    int *tab3 = (int*)malloc(sizeof(int));
    int i=0,j=0,k=0;
    while(i!=taille && j!=taille2){
        if(tab[i]<=tab2[j]){
            if (tab[i] != *(tab3 + k - 1))
            {
                tab3 = (int *)realloc(tab3, (k + 1) * sizeof(int));
                *(tab3 + k) = tab[i];
                k++;i++;
            }
            else
            {
                i++;
            }
        }else{
            if (tab2[j] != *(tab3 + k -1))
            {
                tab3 = (int *)realloc(tab3, (k + 1) * sizeof(int));
                *(tab3 + k) = tab2[j];
                k++;
                j++;
            }
            else
            {
                j++;
            }
        }
    }
    while(i!=taille){
        if (tab[i] != *(tab3 + k - 1))
        {
            tab3 =(int*) realloc(tab3,(k+1)*sizeof(int));
            *(tab3 + k) = tab[i];
            k++;
            i++;
        }
        else
        {
            i++;
        }
    }
    while(j!=taille2){
        if (tab2[j] != *(tab3 + k - 1))
        {
            tab3 = (int *)realloc(tab3, (k + 1) * sizeof(int));
            *(tab3 + k) = tab2[j];
            k++;
            j++;
        }
        else
        {
            j++;
        }
    }
    afficher_tableau(tab3,k);
}