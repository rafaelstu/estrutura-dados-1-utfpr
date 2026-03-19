#include <stdio.h>

void imprimeVetor(int *v,int n){
    for(int i=0;i<n;i++){
        printf("%d\n", *(v+i));
    }
};

int main() {
    int n=4;
    int v[]={10,20,30,40};

    imprimeVetor(v,n);

    return 0;
}
