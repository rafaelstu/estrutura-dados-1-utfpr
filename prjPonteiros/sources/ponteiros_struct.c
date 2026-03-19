#include <stdio.h>
#include <string.h>

typedef struct cliente Cliente;

struct cliente {
  char nome[30], rua[30];
  int numero;
};

void alteraEndereco(Cliente *cli, char rua[], int num) {
  strcpy(cli->rua, rua);
  cli->numero = num;
};

void imprimeCliente(Cliente *cli) {
  printf("\n\nNome: %s", cli->nome);
  printf("\nrua: %s", cli->rua);
  printf("\nnumero: %d", cli->numero);
}

int main() {
  Cliente c1;
  strcpy(c1.nome, "maria");
  strcpy(c1.rua, "rua guarani");
  c1.numero = 10;

  imprimeCliente(&c1);
  alteraEndereco(&c1, "av. tupi", 20);
  imprimeCliente(&c1);

  return 0;
}
