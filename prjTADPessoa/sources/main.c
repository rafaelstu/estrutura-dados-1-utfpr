#include "pessoa.h"
#include <stdio.h>

int main() {
  Pessoa *vetPessoas;
  int n = 0, idade;
  char c;
  char nome[30];

  do {

    printf("informe o nome da pessoa: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", nome);

    printf("informe a idade da pessoa: ");
    scanf("%d", &idade);

    inserePessoas(vetPessoas, nome, idade, n);
    n++;

    printf("inserir mais uma pessoa (s/S)? ");
    setbuf(stdin, NULL);

    scanf("%c", &c);

  } while (c == 's' || c == 'S');

  imprimePessoas(vetPessoas, n);

  liberaVetorPessoas(vetPessoas);

  return 0;
}
