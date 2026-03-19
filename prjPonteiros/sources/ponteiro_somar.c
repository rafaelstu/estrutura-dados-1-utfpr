#include <stdio.h>

void somar(int *soma,int a, int b){
    *soma = a+b;
}

int main() {
    int soma;
    somar(&soma,10,20);
    printf("soma = %d",soma);
  return 0;
}
