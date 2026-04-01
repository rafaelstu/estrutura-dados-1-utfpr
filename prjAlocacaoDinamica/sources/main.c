#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void valorizaMatriz(int **m, int nLinhas, int nColunas) {
  for (int l = 0; l < nLinhas; l++) {
    for (int c = 0; c < nColunas; c++) {
      m[l][c] = rand() % 100;
    }
  }
}

int **somaMatrizes(int **m1, int **m2, int nLinhas, int nColunas) {
  int **resultado = alocaMatriz(nLinhas, nColunas);
  for (int l = 0; l < nLinhas; l++) {
    for (int c = 0; c < nColunas; c++) {
      resultado[l][c] = m1[l][c] + m2[l][c];
    }
  }
  return resultado;
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
  srand(time(NULL));
  int nLinhas = 3, nColunas = 3;

  int **matA = alocaMatriz(nLinhas, nColunas);
  int **matB = alocaMatriz(nLinhas, nColunas);

  valorizaMatriz(matA, nLinhas, nColunas);
  valorizaMatriz(matB, nLinhas, nColunas);

  printf("Matriz A:\n");
  imprimeMatriz(matA, nLinhas, nColunas);
  printf("Matriz B:\n");
  imprimeMatriz(matB, nLinhas, nColunas);

  int **matSoma = somaMatrizes(matA, matB, nLinhas, nColunas);
  printf("Matriz Soma (A + B):\n");
  imprimeMatriz(matSoma, nLinhas, nColunas);

  liberaMatriz(matA, nLinhas);
  liberaMatriz(matB, nLinhas);
  liberaMatriz(matSoma, nLinhas);

  return 0;
}
