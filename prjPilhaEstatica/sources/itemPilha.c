#include "itemPilha.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  int chave;
  // demais campos
};

struct pilha {
  Item vetItem[MAX_TAM];
  int topo;
};

Pilha *criaPilhaVazia() {
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = -1;

  return p;
}

// retorna 1 se cheia ou 0 se nao
int verificaPilhaCheia(Pilha *p) { return (p->topo == (MAX_TAM - 1)); }

// retorna 1 se vazia ou 0 se nao
int verificaPilhaVazia(Pilha *p) { return (p->topo == -1); }

void empilha(Pilha *p, int chave) {
  if (verificaPilhaCheia(p)) {
    printf("erro: a pilha esta cheia\n");
    return;
  }

  Item novoItem;
  novoItem.chave = chave;
  p->topo++;
  p->vetItem[p->topo] = novoItem;
}

void desempilha(Pilha *p) {
  if (verificaPilhaVazia(p)) {
    printf("erro: a pilha esta vazia\n");
    return;
  }

  p->topo--;
}

void imprimePilha(Pilha *p) {
  for (int i = 0; i <= p->topo; i++) {
    printf("chave: %d\n", p->vetItem[i].chave);
  }
}

void liberaPilha(Pilha *p) { free(p); }
