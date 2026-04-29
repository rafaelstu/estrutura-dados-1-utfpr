#include "itemPilha.h"
#include <stdio.h>

int main() {
  Pilha *p = criaPilhaVazia();
  printf("\nempilhando 5 vezes\n");

  empilha(p, 1);
  empilha(p, 2);
  empilha(p, 3);
  empilha(p, 4);
  empilha(p, 5);

  printf("\ntentando empilhar mais um item\n");
  empilha(p, 6);
  imprimePilha(p);

  printf("\ndesempilhando\n");
  desempilha(p);
  imprimePilha(p);

  liberaPilha(p);
  return 0;
}
