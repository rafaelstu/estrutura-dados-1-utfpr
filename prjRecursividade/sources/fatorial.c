// fatorial - abordagem iterativ
#include <stdio.h>
int fatorial(int n) {
  int fat = n;
  for (int i = n - 1; i > 0; i--) {
    fat *= i;
  }
  return fat;
}

// fatorial - abordagem recursiva
int fatorial_rec(int n) {
  if (n == 1) { // caso base - menor instancia do problema
    return 1;
  } else {
    return n * fatorial_rec(n - 1);
  }
}

int main() {

  int n;
  printf("informe um numero para calcular o fatorial: ");
  scanf("%d", &n);
  printf("\nfatorial de %d usando algoritmo iterativo: %d", n, fatorial(n));
  printf("\nfatorial de %d usando algoritmo recursivo: %d", n, fatorial_rec(n));

  return 0;
}
