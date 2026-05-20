#include "itemDeque.h"
#include <stdio.h>

int main() {
  Deque *dq;

  int vazia, cheia, chave = 0, opcao = -1;

  dq = criaDeque();

  do {
    printf("\n===PLAYLIST===");
    printf("\n1) exibir playlist");
    printf("\n2) inserir musica (fim da fila)");
    printf("\n3) inserir musica (vip - inicio da fila)");
    printf("\n4) remover musica do inicio");
    printf("\n5) remover musica do final");
    printf("\n6) calcular duração da playlist");
    printf("\n0) sair");
    printf("\nescolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 0: {
      printf("saindo do programa\n");
      break;
    }
    case 1: {
      imprimeDeque(dq);
      break;
    }
    case 2: {
      char musica[50];
      int bpm, m, s;
      printf("\nnome da musica: ");
      scanf("%s", musica);
      setbuf(stdin, NULL);

      printf("bpm da musica: ");
      scanf("%d", &bpm);
      printf("duração da musica (mm:ss): ");
      scanf("%d:%d", &m, &s);

      insereFinalDeque(dq, chave++, musica, bpm, m, s);
      break;
    }
    case 3: {
      char musica[50];
      int bpm, m, s;

      printf("\nnome da musica: ");
      scanf("%s", musica);
      setbuf(stdin, NULL);

      printf("bpm da musica: ");
      scanf("%d", &bpm);
      printf("duração da musica (mm:ss): ");
      scanf("%d:%d", &m, &s);

      insereInicioDeque(dq, chave++, musica, bpm, m, s);
      break;
    }

    case 4: {
      printf("\nremovendo do inicio do deque");
      removeInicioDeque(dq);
      break;
    }
    case 5: {
      printf("\nremovendo do final do deque");
      removeFinalDeque(dq);
      break;
    }
    case 6: {
      calculaTotalDuracao(dq);
      break;
    }
    default: {
      printf("opção invalida\n");
      break;
    }
    }
  } while (opcao != 0);

  liberaDeque(dq);
  return 0;
}
