#include <stdio.h>

typedef struct dosesVacina DosesVacina;

struct dosesVacina {
  char paciente[50];
  char cidade[30];
  int idade;
};

int main() {
  int i, n = 2;
  DosesVacina vetPacientes[n];
  for (i = 0; i < n; i++) {
    setbuf(stdin, NULL);

    printf("informe o nome do paciente: ");
    scanf("%[^\n]s", vetPacientes[i].paciente);

    setbuf(stdin, NULL);

    printf("informe a cidade do paciente ");
    scanf("%[^\n]s", vetPacientes[i].cidade);

    setbuf(stdin, NULL);

    printf("informe a idade do paciente: ");
    scanf("%d", &vetPacientes[i].idade);
  }

  for (i = 0; i < n; i++) {
    printf("\n\no paciente: %s, da cidade: %s, tem %d anos de idade",
           vetPacientes[i].paciente, vetPacientes[i].cidade,
           vetPacientes[i].idade);
  }

  return 0;
}
