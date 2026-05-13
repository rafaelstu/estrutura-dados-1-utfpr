// impressao de vetor ao contrario
#include <stdio.h>
#include <stdlib.h>
void imprime(int v[], int n) {
  int fat = n;
  for (int i = n - 1; i >= 0; i--) {
    printf("%d\t", v[i]);
  }
}

// imprime - abordagem recursiva
void imprime_rec(int v[], int n) {
  if (n == 0) { // caso base - menor instancia do problema
    return;     // posicao 0 do vetor
  } else {
    printf("%d\t", v[n - 1]);
    imprime_rec(v, n - 1);
  }
}

int main() {

  int n;
  printf("informe o numero de elementos do vetor: ");
  scanf("%d", &n);

  int *vet = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    vet[i] = i; // atribuicao de vlaor para nao deiar o vetor vazio
  }

  printf("\nimpressao de vetor ao vontrario usando algoritmo iterativo:\n");
  imprime(vet, n);
  printf("\nimpressao de vetor ao vontrario usando algoritmo recursivo:\n");
  imprime_rec(vet, n);

  return 0;
}
