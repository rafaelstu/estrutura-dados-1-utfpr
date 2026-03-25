#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverteString(char s[]) {
  int i, j, tamanho;
  tamanho = strlen(s); // quantidade de caracteres
  // char sInvertida[tamanho]; nao eh possivel usar endereco de meomria
  // de variaevl local como retorno de funcao
  char *sInvertida;

  sInvertida = (char *)malloc(tamanho);

  j = 0;
  for (i = tamanho - 1; i >= 0; i--) {
    sInvertida[j] = s[i];
    j++;
  }
  sInvertida[j] = '\0';
  return sInvertida;
}

int main() {

  char *s = "ponteiros";
  char *i = inverteString(s);

  printf("%s", i);

  free(i);
  return 0;
}
