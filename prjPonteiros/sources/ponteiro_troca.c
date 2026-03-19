#include <stdio.h>
#include <string.h>

typedef struct cliente Cliente;

struct cliente {
  char nome[30], rua[30];
  int numero;
};

void troca(int *a, int*b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int main() {
    int a=10,b=20;
    printf("%d,%d",a,b);
    troca(&a,&b);
    printf("%d,%d",a,b);
  return 0;
}
