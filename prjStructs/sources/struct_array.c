#include <stdio.h>

// cria um apelido para substituir as duas palavras
// "struct aluno" por apenas "Aluno"
typedef struct aluno Aluno;
struct aluno {
  char nome[30];
  int ra;
  float coeficiente;
};

Aluno criaAluno(int i) {
  Aluno a;

  setbuf(stdin, NULL);
  printf("\ninforme o nome do aluno %d: ", i + 1);
  scanf("%[^\n]s", a.nome);

  printf("informe o RA do aluno: ");
  scanf("%d", &a.ra);

  printf("informe o coeficiente do aluno: ");
  scanf("%f", &a.coeficiente);

  return a;
};

void imprimeAluno(Aluno a, int i) {
  printf("\nNome do aluno %d: %s\n", i + 1, a.nome);
  printf("RA: %d\n", a.ra);
  printf("Coeficiente: %.4f\n", a.coeficiente);
};

int main() {
  int i, n = 3;
  Aluno vetAlunos[n];
  for (i = 0; i < n; i++) {

    setbuf(stdin, NULL);
    vetAlunos[i] = criaAluno(i);
  };

  printf("\n\n*Dados informados:*\n");

  for (i = 0; i < n; i++) {
    imprimeAluno(vetAlunos[i], i);
  };
  return 0;
}
