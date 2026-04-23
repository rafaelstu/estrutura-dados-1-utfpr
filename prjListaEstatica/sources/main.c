#include "itemLista.h"

#include <stdio.h>

int main() {

  Lista *l;
  int vazia, cheia, chave;

  printf("criando lista vazia\n");
  l = criaListaVazia();

  chave = 1;
  adicionaItemFimLista(l, chave);
  chave = 2;
  adicionaItemFimLista(l, chave);
  chave = 3;
  adicionaItemFimLista(l, chave);
  chave = 7;
  adicionaItemFimLista(l, chave);
  chave = 9;
  adicionaItemFimLista(l, chave);
  chave = 6;
  adicionaItemQualquerPosicao(l, chave, 0);
  ordenaListaPorChave(l);

  printf("\nitens na lista\n");
  imprimeLista(l);

  chave = 8;
  printf("adicionando chave %d\n", chave);
  adicionaItemOrdenadoPorChave(l, chave);

  chave = 5;
  printf("adicionando chave %d\n", chave);
  adicionaItemOrdenadoPorChave(l, chave);

  chave = 4;
  printf("adicionando chave %d\n", chave);
  adicionaItemOrdenadoPorChave(l, chave);

  adicionaItemFimListaComValidacao(l, chave);

  chave = 10;
  adicionaItemFimListaComValidacao(l, chave);

  printf("\nitens na lista\n");
  imprimeLista(l);

  liberaLista(l);
  return 0;
}
