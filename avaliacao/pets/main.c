#include "pets.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int n = 500; // <-- quantidade de pets
               // testei com 50 mil
               // e deu certo
  PetsRafael *pets;

  for (int i = 0; i < n; i++) {
    pets = adicionaPet(
        pets, i, criarData(randDia(rand()), randMes(rand()), 2026),
        randBool(rand()), randBool(rand()), randBool(rand()), randBool(rand()));
  }

  imprimirPets(pets, n, randMes(rand()));
  printf("\n\n");
  imprimirPets(pets, n, 0);
  printf("\n\n");

  // talvez fique quebrado dependendo do tamanho do terminal, mas funciona
  // para grandes quantidades a visualização fica melhor
  // imprimirPetsTabela(pets, n, randMes(rand()));
  // printf("\n\n");
  // imprimirPetsTabela(pets, n, 0);
  // printf("\n\n");

  petsPorMes(pets, n);

  liberaPets(pets, n);
  return 0;
}
