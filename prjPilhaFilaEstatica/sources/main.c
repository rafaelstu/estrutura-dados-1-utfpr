#include "itemFila.h"
#include "itemPilha.h"
#include <stdio.h>
#include <string.h>

int main() {
  Pilha *p = criaPilhaVazia();
  Pilha *pI = criaPilhaVazia();
  char s[10];
  printf("\ninsira um texto de ate 10 caracteres\n");

  scanf("%s", s);

  for (int i = 0; i < strlen(s); i++) {
    empilha(p, s[i]);
  }

  pI = invertePilha(p);

  printf("\npilha normal\n");
  imprimePilha(p);
  printf("\npilha invertida\n");
  imprimePilha(pI);

  printf("\nverificando se as pilhas sao iguais\n");

  if (verificaPilhaIgual(p, pI)) {
    printf("texto é um palindromo");
  } else {
    printf("texto não é um palindromo");
  }

  liberaPilha(p);
  liberaPilha(pI);
  return 0;
}
