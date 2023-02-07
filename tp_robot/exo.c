#include <stdio.h>
#include <stdlib.h>

int main(){
    int nb_lignes=0,i=0,j=0,k=0;
    while(!(nb_lignes>0 && nb_lignes<=20)){
        printf("\nEntrer le nombre de lignes:");
        scanf("%d",&nb_lignes);
    }
        for (i = 1; i <= nb_lignes; ++i)
        {
            k=0;
            for (j = 1; j <= nb_lignes - i; ++j)
            {
                printf("  ");
            }
            while (k != 2 * i - 1)
            {
                printf("* ");
                ++k;
            }
            printf("\n");
        }
}