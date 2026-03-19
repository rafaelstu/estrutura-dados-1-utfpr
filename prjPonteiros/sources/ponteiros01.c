#include <stdio.h>

int main() {
  int n = 10;
  char c = 'a';
  int *pn = &n;  // ponteiro de inteiro que guarda o endereco de n
  char *pc = &c; // ponteiro de char que guarda o endereco de c

  // imprime conteudo das variaveis
  printf("o valor da variavel n eh: %d\n", n);
  printf("o valor da variavel c eh: %c\n", c);
  // imprime o endereco das variaveis
  printf("o endereco da variavel n eh: %ld\n", &n);
  printf("o endereco da variavel c eh: %ld\n", &c);
  // imprime o endereco das variaveis do tipo ponteiro
  printf("pn aponta para o endereco de n que eh: %ld\n", pn);
  printf("pc aponta para o endereco de c que eh: %ld\n", pc);
  // imprime conteudo das variaveis apontadas pelos ponteiros
  printf("no endereco apontado por pn esta o conteudo: %d\n", *pn);
  printf("no endereco apontado por pc esta o conteudo: %c\n", *pc);

  *pn = 20;
  printf("agora no endereco apontado por pn esta o conteudo: %d\n", *pn);
  printf("o valor da variavel n eh: %d\n", n);

  return 0;
}
