#include "gestao.h"
#include <stdio.h>

int main() {
  Pessoa *vetPessoas;
  int nP = 0;
  int c;
  char nome[32];
  int d, m, a;
  printf("GESTAO DE STREAMINGS\n");
  do {
    printf("informe o nome do contratante %d: ", nP + 1);
    setbuf(stdin, NULL);
    scanf("%[^\n]s", nome);
    printf("data de nascimento (dd/mm/aaaa): ");
    setbuf(stdin, NULL);
    scanf("%d/%d/%d", &d, &m, &a);
    Data *data = dataNova(d, m, a);

    vetPessoas = adicionaPessoa(vetPessoas, nome, data, nP);

    do {
      char nomeS[32];
      float valor;

      printf("informe o nome do servico contratado %d: ",
             vetPessoas[nP].qtdServicos + 1);
      setbuf(stdin, NULL);
      scanf("%[^\n]s", nomeS);

      printf("valor: R$ ");
      scanf("%f", &valor);

      vetPessoas[nP].servicos = adicionaServico(
          vetPessoas[nP].servicos, nomeS, valor, vetPessoas[nP].qtdServicos);
      vetPessoas[nP].qtdServicos++;

      printf("informar outro servico? (1=sim/0=nao) ");
      scanf("%d", &c);
    } while (c == 1);
    nP++;
    printf("informar outro contratante? (1=sim/0=nao) ");
    scanf("%d", &c);
    printf("\n");
  } while (c == 1);

  printf("dados cadastrados:\n");

  imprimePessoas(vetPessoas, nP);

  liberaPessoas(vetPessoas, nP);

  return 0;
}
