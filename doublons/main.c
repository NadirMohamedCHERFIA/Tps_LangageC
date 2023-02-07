#include <stdio.h>
#include <stdlib.h>

int TAB1[]={1,2,3,4,5,6,7,8,9};
int TAB2[]={2,3,5,10,11};

int main(void){
    int taille1 = sizeof(TAB1)/sizeof(TAB1[0]);
    int taille2 = sizeof(TAB2)/sizeof(TAB2[0]);
    int i=0,j=0,k=0,tmp=0;
    int *TAB3 = (int*)malloc(sizeof(int));
    for(i=0;i<taille1;i++){
        for(j=0;j<taille2;j++){
            if(TAB1[i]==TAB2[j]){
                TAB3 = (int*)realloc(TAB3,(k+1)*sizeof(int));
                TAB3[k++] = TAB1[i];
            }
        }
    }
    for(int m=0;m<k;m++){
        printf("%d\t",TAB3[m]);
    }
}