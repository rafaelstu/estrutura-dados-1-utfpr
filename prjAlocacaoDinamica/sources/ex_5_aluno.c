#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

struct aluno {
  char nome[60];
  char email[60];
  int ra;
  long int telefone;
};

int main() {
  int qtd, i;
  Aluno *v;

  printf("informe a qtd de alunos: ");
  scanf("%d", &qtd);

  v = (Aluno *)malloc(qtd * sizeof(Aluno));

  for (i = 0; i < qtd; i++) {
    printf("aluno %d: \n", i + 1);
    printf("informe o nome: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", v[i].nome);

    printf("informe o email: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", v[i].email);

    printf("informe o ra: ");
    scanf("%d", &v[i].ra);

    printf("informe o telefone: ");
    scanf("%ld", &v[i].telefone);
  }
  printf("\n");

  for (i = 0; i < qtd; i++) {
    printf("aluno %d\n", i + 1);
    printf("ra: %d\n", v[i].ra);
    printf("nome: %s\n", v[i].nome);
    printf("telefone: %ld\n", v[i].telefone);
    printf("email: %s\n", v[i].email);
    printf("\n");
  }

  free(v);
  return 0;
}
