#include "itemFila.h"
#include <stdio.h>

// escolhi a fila pelo FIFO.
// hipoteticamente, o que é
// enviado antes, chega antes
int main() {
  int opcao = -1;
  Fila *f = criaFilaVazia();

  do {
    printf("\nGESTÃO DE LOGÍSTICA");
    printf("\n1) adicionar pacote");
    printf("\n2) excluir pacote (ultimo)");
    printf("\n3) busca por peso");
    printf("\n4) imprimir itens");
    printf("\n5) validar código");
    printf("\n0) sair");
    printf("\nescolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 0: {
      printf("saindo do programa\n");
      break;
    }
    case 1: {
      int cod;
      float p, l, a, c;
      printf("Código base (8 digitos): ");
      scanf("%d", &cod);
      printf("Peso (kg): ");
      scanf("%f", &p);
      printf("Largura (cm): ");
      scanf("%f", &l);
      printf("Altura (cm): ");
      scanf("%f", &a);
      printf("Comprimento (cm): ");
      scanf("%f", &c);
      enfileira(f, cod, p, l, a, c);
      break;
    }
    case 2: {
      desenfileira(f);
      break;
    }
    case 3: {
      float p, v;
      printf("digite o peso para busca: ");
      scanf("%f", &p);
      printf("digite a variabilidade para mais/menos (0 para exato): ");
      scanf("%f", &v);
      printf("\n");
      encontraItensPorPeso(f, p, v);
      break;
    }
    case 4: {
      printf("\nimpressão com for\n");
      imprimeFila(f);
      printf("\nimpressão recursiva\n");
      imprimeFilaRecursiva(f, getInicioFila(f), 0);
      break;
    }
    case 5: {
      int codCompleto;
      printf("informe o codigo com o digito verificador: ");
      scanf("%d", &codCompleto);

      if (validaChecksum(codCompleto)) {
        printf("o codigo é valido!\n");
      } else {
        printf("erro: codigo invalido\n");
      }
      break;
    }
    default: {
      printf("opção invalida\n");
      break;
    }
    }
  } while (opcao != 0);
  liberaFila(f);
  return 0;
}
