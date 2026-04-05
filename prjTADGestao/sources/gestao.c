#include "gestao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
  int d, m, a;
};

struct servico {
  char nome[32];
  float valor;
};

struct pessoa {
  char nome[32];
  Data *dataNascimento;
  Servico *servicos;
  int qtdServicos;
};

Data *dataNova(int d, int m, int a) {
  Data *dt = (Data *)malloc(sizeof(Data));

  dt->a = a;
  dt->m = m;
  dt->d = d;

  return dt;
}

void imprimeData(Data *d) { printf("%d/%d/%d", d->d, d->m, d->a); }

void liberaData(Data *d) { free(d); }

Servico *adicionaServico(Servico *vet, char nome[], float valor, int n) {
  if (n == 0) {
    vet = (Servico *)malloc(sizeof(Servico));
  } else {
    vet = (Servico *)realloc(vet, (n + 1) * sizeof(Servico));
  }

  strcpy(vet[n].nome, nome);
  vet[n].valor = valor;

  return vet;
}

void imprimeServicos(Servico *vet, int n) {
  for (int i = 0; i < n; i++) {
    printf(". %s - valor: R$ %.2f\n", vet[i].nome, vet[i].valor);
  }
}

void liberaServicos(Servico *vet) { free(vet); }

Pessoa *adicionaPessoa(Pessoa *vet, char nome[], Data *d, int n) {
  if (n == 0) {
    vet = (Pessoa *)malloc(sizeof(Pessoa));
  } else {
    vet = (Pessoa *)realloc(vet, (n + 1) * sizeof(Pessoa));
  }

  strcpy(vet[n].nome, nome);
  vet[n].dataNascimento = d;
  vet[n].qtdServicos = 0;
  vet[n].servicos = NULL;

  return vet;
}

void imprimePessoas(Pessoa *vet, int n) {
  for (int i = 0; i < n; i++) {
    printf("\nnome: %s\n", vet[i].nome);

    printf("data nasc.: ");
    imprimeData(vet[i].dataNascimento);

    printf("\nservicos contratados:\n");
    imprimeServicos(vet[i].servicos, vet[i].qtdServicos);
  }
}

void liberaPessoas(Pessoa *vet, int n) {
  for (int i = 0; i < n; i++) {
    liberaData(vet[i].dataNascimento);
    liberaServicos(vet[i].servicos);
  }

  free(vet);
}
