#include "itemPilha.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  char chave;
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

void empilha(Pilha *p, char chave) {
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

Pilha *invertePilha(Pilha *p) {
  Pilha *pilhaInvertida;

  pilhaInvertida = criaPilhaVazia();

  for (int i = p->topo; i >= 0; i--) {
    empilha(pilhaInvertida, p->vetItem[i].chave);
  }

  return pilhaInvertida;
}

Pilha *normalizaPilha(Pilha *p) {
  Pilha *pN = criaPilhaVazia();

  for (int i = 0; i <= p->topo; i++) {
    char chave = p->vetItem[i].chave;
    if (chave != ' ' && chave != '.') {
      empilha(pN, chave);
    }
  }

  return pN;
}

// 1 true, 0 false
int verificaPilhaIgual(Pilha *p1, Pilha *p2) {
  Pilha *pN1 = normalizaPilha(p1);
  Pilha *pN2 = normalizaPilha(p2);

  int resultado = 1;

  if (pN1->topo != pN2->topo) {
    resultado = 0;
  } else {
    for (int i = 0; i <= pN1->topo; i++) {
      if (pN1->vetItem[i].chave != pN2->vetItem[i].chave) {
        resultado = 0;
        break;
      }
    }
  }

  liberaPilha(pN1);
  liberaPilha(pN2);

  return resultado;
}

void imprimePilha(Pilha *p) {
  for (int i = 0; i <= p->topo; i++) {
    printf("chave: %c\n", p->vetItem[i].chave);
  }
}

void liberaPilha(Pilha *p) { free(p); }
