#include <stdio.h>
#include <stdlib.h>

int main() {
  int *vet;
  int num = 5;

  vet = (int *)malloc(num * sizeof(int));

  if (vet) {

    int i;

    for (i = 0; i < num; i++) {
      vet[i] = i + 1;
    }

    for (i = 0; i < num; i++) {
      printf("\n posicao %d: %d", i, vet[i]);
    }

    printf("\n");

    num = 3;
    vet = (int *)realloc(vet, num * sizeof(int));

    for (i = 0; i < num; i++) {
      printf("\n posicao %d: %d", i, vet[i]);
    }

    printf("\n");

    num = 10;
    vet = (int *)realloc(vet, num * sizeof(int));

    for (i = 0; i < num; i++) {
      printf("\n posicao %d: %d", i, vet[i]);
    }
  }

  // libera da memoria o vetor alocado dinamicamente
  free(vet);
  return 0;
}
