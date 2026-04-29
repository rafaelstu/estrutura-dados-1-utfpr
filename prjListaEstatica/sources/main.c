#include "itemLista.h"

#include <stdio.h>

int main() {

  Lista *l, *lC, *lI, *lU;
  int vazia, cheia, chave;

  printf("criando lista vazia\n");
  l = criaListaVazia();
  lC = criaListaVazia();

  chave = 1;
  adicionaItemFimLista(l, chave);
  chave = 12;
  adicionaItemFimLista(l, chave);
  chave = 63;
  adicionaItemFimLista(l, chave);
  chave = 7;
  adicionaItemFimLista(l, chave);
  chave = 9;
  adicionaItemFimLista(l, chave);

  printf("\ncopiando lista\n");
  copiaLista(lC, l);

  chave = 6;
  adicionaItemQualquerPosicao(l, chave, 0);
  ordenaListaPorChave(l);

  printf("\nitens na lista\n");
  imprimeLista(l);

  chave = 18;
  printf("adicionando chave %d\n", chave);
  adicionaItemOrdenadoPorChave(l, chave);

  chave = 15;
  printf("adicionando chave %d\n", chave);
  adicionaItemOrdenadoPorChave(l, chave);

  chave = 4;
  printf("adicionando chave %d\n", chave);
  adicionaItemOrdenadoPorChave(l, chave);

  adicionaItemFimListaComValidacao(l, chave);

  chave = 10;
  adicionaItemFimListaComValidacao(l, chave);

  printf("\nitens na lista 1\n");
  imprimeLista(l);

  printf("\nitens na lista copia\n");
  imprimeLista(lC);

  lI = interseccaoLista(l, lC);
  printf("\nitens intersecção listas\n");
  imprimeLista(lI);

  printf("\nunindo listas\n");

  lU = uniaoLista(l, lC);
  ordenaListaPorChave(lU);
  printf("\nitens uniao listas\n");
  imprimeLista(lU);

  liberaLista(l);
  liberaLista(lC);
  liberaLista(lI);
  liberaLista(lU);
  return 0;
}
