#include <stdio.h>

typedef struct aluno Aluno;
struct aluno {
  char nome[50];
  int matricula;
  float n1, n2, n3;
  float media;
};

Aluno criaAluno(int i) {
  Aluno a;

  setbuf(stdin, NULL);
  printf("\ninforme o nome do aluno: ");
  scanf("%[^\n]s", a.nome);

  printf("informe a matriula do aluno: ");
  scanf("%d", &a.matricula);

  printf("informe a nota 1 do aluno: ");
  scanf("%f", &a.n1);

  printf("informe a nota 2 do aluno: ");
  scanf("%f", &a.n2);

  printf("informe a nota 3 do aluno: ");
  scanf("%f", &a.n3);

  a.media = (a.n1 + a.n2 + a.n3) / 3;

  return a;
};

void imprimeAlunoCabecalho(void) {
  printf("\n\nNome\t");
  printf("Matricula\t");
  printf("Nota 1\t");
  printf("Nota 2\t");
  printf("Nota 3\t");
  printf("Media\n");
};

void imprimeAlunoValores(Aluno a) {
  printf("%s\t", a.nome);
  printf("%d\t\t", a.matricula);
  printf("%.2f\t", a.n1);
  printf("%.2f\t", a.n2);
  printf("%.2f\t", a.n3);
  printf("%.2f\n", a.media);
};

int main() {
  int i, n = 2;
  Aluno vetAlunos[n], alunoMaiorNota1 = {.n1 = -1},
                      alunoMaiorMedia = {.media = -1},
                      alunoMenorMedia = {.media = 11};
  for (i = 0; i < n; i++) {
    vetAlunos[i] = criaAluno(i);
  };

  for (i = 0; i < n; i++) {
    if (vetAlunos[i].n1 > alunoMaiorNota1.n1) {
      alunoMaiorNota1 = vetAlunos[i];
    }
    if (vetAlunos[i].media > alunoMaiorMedia.media) {
      alunoMaiorMedia = vetAlunos[i];
    }
    if (vetAlunos[i].media < alunoMenorMedia.media) {
      alunoMenorMedia = vetAlunos[i];
    }
  };

  printf("\nAluno com maior nota 1: %s, nota: %.2f", alunoMaiorNota1.nome,
         alunoMaiorNota1.n1);
  printf("\nAluno com maior media geral: %s, media: %.2f", alunoMaiorMedia.nome,
         alunoMaiorMedia.media);
  printf("\nAluno com menor media geral: %s, media: %.2f", alunoMenorMedia.nome,
         alunoMenorMedia.media);

  imprimeAlunoCabecalho();
  for (i = 0; i < n; i++) {
    imprimeAlunoValores(vetAlunos[i]);
  };

  return 0;
}
