#include "itemFila.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  int codRastreio;
  float peso;
  float largura;
  float altura;
  float comprimento;
};

struct fila {
  Item vetItem[MAX_TAM];
  int primeiro;
  int ultimo;
  int tamanho;
};

// retorna 1 se true, 0 se false
int verificaFilaCheia(Fila *f) { return f->tamanho == MAX_TAM; }
int verificaFilaVazia(Fila *f) { return f->tamanho == 0; }
int verificaCodigoIgual(Fila *f, int codRastreio) {
  int i = f->primeiro;
  for (int t = 0; t < f->tamanho; t++) {
    if (f->vetItem[i].codRastreio == codRastreio) {
      return 1;
    }
    i = (i + 1) % MAX_TAM;
  }
  return 0;
}

int validaCodigo(Item item) { return 0; }

Fila *criaFilaVazia() {
  Fila *f = malloc(sizeof(Fila));

  f->primeiro = 0;
  f->ultimo = 0;
  f->tamanho = 0;

  return f;
}

// https://stackoverflow.com/questions/40005990/write-a-program-in-c-to-apply-luhns-algorithm-for-credit-card-validation
// usei o gemini para fazer o cria checksum e adaptar o valida com base nesse
// link ^

int criaChecksum(int codRastreio) {
  int sum = 0;
  int temp = codRastreio;
  int i = 1;

  while (temp > 0) {
    int digit = temp % 10;

    if (i % 2 != 0) {
      digit *= 2;
      if (digit > 9)
        digit -= 9;
    }

    sum += digit;
    temp /= 10;
    i++;
  }

  int digitoVerificador = (10 - (sum % 10)) % 10;
  return (codRastreio * 10) + digitoVerificador;
}

int validaChecksum(int codCompleto) {
  int sum = 0;
  int temp = codCompleto;
  int i = 1;

  while (temp > 0) {
    int digit = temp % 10;

    if (i % 2 == 0) {
      digit *= 2;
      if (digit > 9)
        digit -= 9;
    }

    sum += digit;
    temp /= 10;
    i++;
  }

  return (sum % 10 == 0);
}

void enfileira(Fila *f, int codRastreio, float peso, float largura,
               float altura, float comprimento) {
  if (verificaFilaCheia(f)) {
    printf("erro: a fila esta cheia\n");
    return;
  }

  if (verificaCodigoIgual(f, codRastreio)) {
    printf("erro: ja existe um item com este código\n");
    return;
  };

  Item novoItem;

  novoItem.altura = altura;
  novoItem.largura = largura;
  novoItem.peso = peso;
  novoItem.comprimento = comprimento;
  novoItem.codRastreio = criaChecksum(codRastreio);

  f->vetItem[f->ultimo] = novoItem;
  f->ultimo = (f->ultimo + 1) % MAX_TAM;
  f->tamanho++;
}

void desenfileira(Fila *f) {
  if (verificaFilaVazia(f)) {
    printf("erro: a fila esta vazia\n");
    return;
  }

  f->primeiro = (f->primeiro + 1) % MAX_TAM;
  f->tamanho--;
  printf("item removido\n");
}

void imprimeItem(Item item) {
  printf("\ncód rastreio: %d\n", item.codRastreio);
  if (validaChecksum(item.codRastreio)) {
    printf("código de rastreio válido\n");
  } else {
    printf("código de rastreio inválido\n");
  }
  printf("altura (cm): %.2f\n", item.altura);
  printf("comprimento (cm): %.2f\n", item.comprimento);
  printf("largura (cm): %.2f\n", item.largura);
  printf("peso (kg): %.2f\n", item.peso);
}

int getInicioFila(Fila *f) { return f->primeiro; }

void encontraItensPorPeso(Fila *f, float peso, int variabilidade) {
  int i = f->primeiro;
  for (int t = 0; t < f->tamanho; t++) {
    int pesoItem = f->vetItem[i].peso;
    if (pesoItem >= (peso - variabilidade) &&
        pesoItem <= (peso + variabilidade)) {
      imprimeItem(f->vetItem[i]);
    }
  }
}

void imprimeFila(Fila *f) {
  int i = f->primeiro;
  for (int t = 0; t < f->tamanho; t++) {
    imprimeItem(f->vetItem[i]);
    i = (i + 1) % MAX_TAM;
  }
}

void imprimeFilaRecursiva(Fila *f, int indiceAtual, int cont) {
  if (cont == f->tamanho)
    return;

  imprimeItem(f->vetItem[indiceAtual]);
  imprimeFilaRecursiva(f, (indiceAtual + 1) % MAX_TAM, cont + 1);
}

void liberaFila(Fila *f) { free(f); }
