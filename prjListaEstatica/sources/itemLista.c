#include "itemLista.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  int chave;
  // demais campos
};

struct lista {
  Item vetItem[MAXTAM];
  int ultimo; // armazena última posição em
              // uso na lista
};

Lista *criaListaVazia() {
  Lista *l = malloc(sizeof(Lista));
  l->ultimo = -1; // indica que não há itens na lista
  return l;
}

// retorna 1 se a lista esta vazia
//  ou zero se nao esta
int verificaListaVazia(Lista *l) { return (l->ultimo == -1); }

// retorna 1 se a lista esta cheia
//  ou zero se nao esta
int verificaListaCheia(Lista *l) { return (l->ultimo == MAXTAM - 1); }

void adicionaItemFimLista(Lista *l, int chave) {
  if (verificaListaCheia(l)) {
    printf("erro: lista cheia.\n");
    return;
  }

  Item novoItem;
  novoItem.chave = chave;
  l->ultimo++;
  l->vetItem[l->ultimo] = novoItem;
}

void adicionaItemQualquerPosicao(Lista *l, int chave, int posicao) {
  if (posicao > l->ultimo || posicao < 0) {
    printf("erro: posicao invalida\n");
    return;
  }

  for (int i = l->ultimo; i >= posicao; i--) {
    l->vetItem[i + 1] = l->vetItem[i];
  }

  Item novoItem;
  novoItem.chave = chave;

  l->vetItem[posicao] = novoItem;
  l->ultimo++;
}

void imprimeLista(Lista *l) {
  for (int i = 0; i <= l->ultimo; i++) {
    printf("chave: %d\n", l->vetItem[i].chave);
  }
}

// retorna o indice do item com a chave buscada
// ou -1 se nao encontrar
int buscaItemPorChave(Lista *l, int chave) {
  int i = 0;
  while ((i <= l->ultimo) && (l->vetItem[i].chave != chave)) {
    i++;
  }
  if (i <= l->ultimo) {
    return i;
  }
  return -1;
}

void removeItem(Lista *l, int chave) {
  int posicao = buscaItemPorChave(l, chave);

  if (posicao == -1) {
    printf("erro: item nao encontrado\n");
    return;
  }

  for (int i = posicao; i <= l->ultimo; i++) {
    l->vetItem[i] = l->vetItem[i + 1];
  }
  l->ultimo--;
}

void liberaLista(Lista *l) { free(l); }
