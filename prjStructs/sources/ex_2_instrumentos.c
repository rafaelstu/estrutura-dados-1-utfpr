#include <stdio.h>

typedef struct instrumento Instrumento;

struct instrumento {
  char modelo[50];
  char marca[30];
  float preco;
};

int main() {
  int i, n = 5;
  float p = -1;
  Instrumento vetInstrumentos[n];

  for (i = 0; i < n; i++) {
    setbuf(stdin, NULL);

    printf("informe o modelo do instrumento: ");
    scanf("%[^\n]s", vetInstrumentos[i].modelo);

    setbuf(stdin, NULL);

    printf("informe a marca do instrumento ");
    scanf("%[^\n]s", vetInstrumentos[i].marca);

    setbuf(stdin, NULL);

    printf("informe o preço do instrumento: ");
    scanf("%f", &vetInstrumentos[i].preco);
  }

  do {
    setbuf(stdin, NULL);

    printf("\ninforme um valor: ");
    scanf("%f", &p);

    for (i = 0; i < n; i++) {
      if (vetInstrumentos[i].preco < p) {
        printf(
            "\n o item modelo: %s, marca: %s custa: %.2f, que é menos de %.2f",
            vetInstrumentos[i].modelo, vetInstrumentos[i].marca,
            vetInstrumentos[i].preco, p);
      }
    }
  } while (p != 0);

  return 0;
}
