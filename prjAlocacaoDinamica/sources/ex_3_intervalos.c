#include <stdio.h>
#include <stdlib.h>

void validarIntervalos(int *inf, int *sup) {

  int j;

  if (sup > inf) {
    j = *sup;
    *sup = *inf;
    *inf = j;
  }
}

int *intervalo(int inf, int sup) {
  int i, j;
  int *v;

  v = (int *)malloc(j * sizeof(int));
  for (i = 0, j = inf + 1; j < sup; i++, j++) {
    v[i] = j;
  }

  return v;
}

int main() {
  int inf, sup, i, j;
  int *v;

  printf("informe o limite inferior: ");
  scanf("%d", &inf);

  printf("informe o limite superior: ");
  scanf("%d", &sup);

  validarIntervalos(&inf, &sup);

  v = intervalo(inf, sup);

  for (i = 0, j = inf + 1; j < sup; i++, j++) {
    printf("p%d: %d\n", i, v[i]);
  }

  free(v);
  return 0;
}
