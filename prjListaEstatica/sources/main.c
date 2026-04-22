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
  chave = 4;
  adicionaItemFimLista(l, chave);
  chave = 5;
  adicionaItemFimLista(l, chave);

  printf("\nitens na lista\n");
  imprimeLista(l);

  printf("tentando adicionar o 6º item na 3ª posicao\n");

  printf("adicionando 6º item\n");
  chave = 6;
  adicionaItemQualquerPosicao(l, chave, 2);

  printf("\nitens na lista\n");
  imprimeLista(l);

  liberaLista(l);
  return 0;
}
