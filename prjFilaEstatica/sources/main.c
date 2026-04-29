#include "itemFila.h"
#include <stdio.h>

int main() {

  Fila *f = criaFilaVazia();

  printf("enfileirando 5 itens\n");
  enfileira(f, 1);
  enfileira(f, 2);
  enfileira(f, 3);
  enfileira(f, 4);
  enfileira(f, 5);

  printf("\ntentando enfileirar mais um item: \n");
  enfileira(f, 6);
  imprimeFila(f);

  printf("\ndesenfileirando\n");
  desenfileira(f);
  imprimeFila(f);

  liberaFila(f);
  return 0;
}
