#include <stdio.h>
#include <stdlib.h>

int main() {
  int qtd, i;
  float *v, max = 0, min = 11, tot = 0;

  printf("informe a qtd de notas: ");
  scanf("%d", &qtd);

  v = (float *)malloc(qtd * sizeof(float));

  for (i = 0; i < qtd; i++) {
    printf("informe a nota %d: ", i + 1);
    scanf("%f", &v[i]);

    if (v[i] < 0 || v[i] > 10) {
      printf("nota invalida, tente de novo\n");
      i--;
    } else {
      tot += v[i];
      if (v[i] > max) {
        max = v[i];
      }

      if (v[i] < min) {
        min = v[i];
      }
    }
  }

  printf("media simples: %.2f\n", tot / qtd);
  printf("maior nota: %.2f\n", max);
  printf("menor nota: %.2f\n", min);

  free(v);
  return 0;
}
