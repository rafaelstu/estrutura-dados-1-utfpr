#include <stdio.h>

int main() {
  short int vet[] = {20, 30, 40, 50, 60}; // short int ocupa 2 bytes
  short int *p = vet; // como o nome do vetor já é ponteiro, nao precisa o &

  printf("p aponta para o endereço: %ld\n", p); // endereco em vet[0]
  printf("o valor guardado no endereco acima eh: %d\n", *p); // valor em vet[0]

  p = p + 2; // aritmetica de ponteiros, avança duas posições
  printf("\np=p+2\n");
  printf("p aponta para o endereço: %ld\n", p); // endereco em vet[2]
  printf("o valor guardado no endereco acima eh: %d\n", *p); // valor em vet[2]

  p = p - 1; // aritmetica de ponteiros, volta uma posição
  printf("\np=p-1\n");
  printf("p aponta para o endereço: %ld\n", p); // endereco em vet[1]
  printf("o valor guardado no endereco acima eh: %d\n", *p); // valor em vet[1]

  return 0;
}
