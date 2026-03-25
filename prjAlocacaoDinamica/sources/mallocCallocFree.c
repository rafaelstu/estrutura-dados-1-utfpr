#include <stdio.h>
#include <stdlib.h>

int main() {
  int *vet;
  int num;
  printf("informe o nnumero de elementos que pretende armazenar: ");
  scanf("%d", &num);

  // alocação de memoria necessaria para armazenar a quantidade informada pelo
  // usuario sem verificar se há lixo de memória

  //  vet = (int *)malloc(num * sizeof(int));

  // verificando e limpando se há lixo de memória
  vet = (int *)calloc(num, sizeof(int));
  if (vet == NULL) {
    printf("\n erro: nao foi posivel alocar memoria.\n");
    system("pause");
    exit(1);
  }

  int i;

  for (i = 0; i < num; i++) {
    printf("digite o valor a posicao %d: ", i);
    scanf("%d", &vet[i]);
  }

  for (i = 0; i < num; i++) {
    printf("\n posicao %d: %d", i, vet[i]);
  }

  // libera da memoria o vetor alocado dinamicamente
  free(vet);
  return 0;
}
