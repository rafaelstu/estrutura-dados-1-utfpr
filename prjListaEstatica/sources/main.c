#include "itemLista.h"

#include <stdio.h>

int main() {

  Lista *l;
  int vazia, cheia, chave;

  printf("criando lista vazia\n");
  l = criaListaVazia();

  vazia = verificaListaVazia(l);
  printf("lista vazia? %d\n", vazia);

  cheia = verificaListaCheia(l);
  printf("lista cheia? %d\n", cheia);

  printf("adicionando 1º item\n");
  chave = 1;
  adicionaItemFimLista(l, chave);

  vazia = verificaListaVazia(l);
  printf("lista vazia? %d\n", vazia);

  printf("adicionando 2º item\n");
  chave = 2;
  adicionaItemFimLista(l, chave);

  printf("adicionando 3º item\n");
  chave = 3;
  adicionaItemFimLista(l, chave);

  printf("adicionando 4º item\n");
  chave = 4;
  adicionaItemFimLista(l, chave);

  printf("adicionando 5º item\n");
  chave = 5;
  adicionaItemFimLista(l, chave);

  printf("tentando adicionar o 6º item\n");

  printf("adicionando 6º item\n");
  chave = 6;
  adicionaItemFimLista(l, chave);

  printf("\nitens na lista\n");
  imprimeLista(l);

  printf("posicao do item com chave = 4: %d\n", buscaItemPorChave(l, 4));
  printf("posicao do item com chave = 6: %d\n", buscaItemPorChave(l, 6));

  printf("tentando remover item com chave 6\n");
  removeItem(l, 6);
  printf("tentando remover item com chave 3\n");
  removeItem(l, 3);
  imprimeLista(l);

  liberaLista(l);
  return 0;
}
