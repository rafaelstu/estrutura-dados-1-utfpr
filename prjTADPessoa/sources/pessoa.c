#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
  int idade;
  char nome[30];
};

Pessoa *inserePessoas(Pessoa *vet, char nome[], int idade, int nPessoas) {

  if (nPessoas == 0) {
    vet = (Pessoa *)malloc(sizeof(Pessoa));

  } else {
    vet = (Pessoa *)realloc(vet, (nPessoas + 1) * sizeof(Pessoa));
  }

  strcpy(vet[nPessoas].nome, nome);

  vet[nPessoas].idade = idade;

  return vet;
}

void imprimePessoas(Pessoa *vet, int nPessoas) {
  for (int i = 0; i <= nPessoas; i++) {
    printf("%s - %d\n", vet[i].nome, vet[i].idade);
  }
}

void liberaVetorPessoas(Pessoa *vet) { free(vet); }
