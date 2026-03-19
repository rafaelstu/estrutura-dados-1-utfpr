#include <stdio.h>

void alteraVetor(int *v, int n) { v[0] = n; }

char *copiaParteStr(char c, char *str) {
  while (*str && c != *str) { // só para se c for igual ao conteudo
                              // do ponteiro, ou string acabar;
    str = str + 1;
  }
  return str; // retorna o ponteiro contendo o restante da string
}

int main() {
  int n = 5;
  int v[] = {1, 2, 3, 4, 5};
  alteraVetor(v, n);

  for (int i = 0; i < n; i++) {
    printf("%d\t", v[i]);
  }

  char s[] = "boa noite!";
  char c = 'a';
  char *pc;
  pc = copiaParteStr(c, s);

  if (*pc) {              // se há um valor valido associado ao ponteiro
    printf("\n\n%s", pc); // imprime a string a partir do endereco de memoria
  } else {
    printf("\n\ncaractere nao encontrado na string.");
  }
  return 0;
}
