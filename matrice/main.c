#include <stdio.h>
#include <stdlib.h>

int M[4][3]={
    {1,2,3},
    {1,2,3},
    {1,2,3},
    {1,2,3}
};


void aff(int M[4][3]){
    for(int i = 0; i<4;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",M[i][j]);
        }
    }
}

int main(){
    aff(M);
}