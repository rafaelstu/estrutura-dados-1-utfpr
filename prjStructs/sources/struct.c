#include <stdio.h>

// cria um apelido para substituir as duas palavras
// "struct aluno" por apenas "Aluno"
typedef struct aluno Aluno;
struct aluno {
  char nome[30];
  int ra;
  float coeficiente;
};

int main() {
  Aluno aluno1;

  printf("informe o nome do aluno: ");
  scanf("%[^\n]s", aluno1.nome);

  printf("informe o RA do aluno: ");
  scanf("%d", &aluno1.ra);

  printf("informe o coeficiente do aluno: ");
  scanf("%f", &aluno1.coeficiente);

  printf("Nome alnuo1: %s\n", aluno1.nome);
  printf("RA alnuo1: %d\n", aluno1.ra);
  printf("Coeficiente alnuo1: %.4f\n", aluno1.coeficiente);

  Aluno aluno2 = {"Rafael Stuzata", 2820994, 0.9311};

  // sobrescreve os dados do aluno 2
  aluno2 = aluno1;

  printf("Nome alno2: %s\n", aluno2.nome);
  printf("RA alno2: %d\n", aluno2.ra);
  printf("Coeficiente alno2: %.4f\n", aluno2.coeficiente);

  return 0;
}
