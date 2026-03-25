#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int nLinhas, int nColunas) {
  int **m, l;
  // 1 - alocamos um vetor com um ponteiro para cada linha
  m = (int **)malloc(nLinhas * sizeof(int *));

  // 2 - fazemos cada ponteiro apontar para uma linha
  for (l = 0; l < nLinhas; l++) {
    m[l] = (int *)calloc(nColunas, sizeof(int));
  }

  return m;
}

void imprimeMatriz(int **m, int nLinhas, int nColunas) {
  for (int l = 0; l < nLinhas; l++) {
    for (int c = 0; c < nColunas; c++) {
      // printf("%ld\t", &m[l][c]); exibe as posições dos ponteiros
      printf("%d\t", m[l][c]);
      // tambem poderia ser usado *(*(m+l)+c)
    }
    printf("\n");
  }
}

void liberaMatriz(int **m, int nLinhas) {
  for (int l = 0; l < nLinhas; l++) {
    free(m[l]); // libera os vetores apontados por cada linha
  }
  free(m); // libera a matrzi como um trodo
}

int main() {
  int nLinhas = 4, nColunas = 5;
  int **m = alocaMatriz(nLinhas, nColunas);

  imprimeMatriz(m, nLinhas, nColunas);
  liberaMatriz(m, nLinhas);

  return 0;
}
