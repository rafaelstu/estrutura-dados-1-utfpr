#include "pets.h"
#include <stdio.h>
#include <stdlib.h>

struct data {
  int a, m, d;
};

struct petsRafael {
  Data *dataRegistroPet;
  int adotado;
  int castrado;
  int vacinado;
  int encontradoNaRua;
};

Data *criarData(int d, int m, int a) {
  Data *dt = (Data *)malloc(sizeof(Data));

  dt->a = a;
  dt->m = m;
  dt->d = d;

  return dt;
}

void imprimeData(Data *d) { printf("%02d/%02d/%04d", d->d, d->m, d->a); }

void liberaData(Data *d) { free(d); }

PetsRafael *adicionaPet(PetsRafael *pets, int n, Data *d, int adotado,
                        int castrado, int vacinado, int encontradoNaRua) {

  if (n == 0) {
    pets = (PetsRafael *)malloc(sizeof(PetsRafael));
  } else {
    pets = (PetsRafael *)realloc(pets, (n + 1) * sizeof(PetsRafael));
  }

  pets[n].dataRegistroPet = d;
  pets[n].adotado = adotado;
  pets[n].castrado = castrado;
  pets[n].vacinado = vacinado;
  pets[n].encontradoNaRua = encontradoNaRua;
  return pets;
}

void handleBool(int b) {
  if (b) {
    printf("sim");
  } else {
    printf("nao");
  }
}

void imprimirPet(PetsRafael pet) {
  printf("\ndata de registro: ");
  imprimeData(pet.dataRegistroPet);
  printf("\nadotado? ");
  handleBool(pet.adotado);
  printf("\ncastrado? ");
  handleBool(pet.castrado);
  printf("\nvacinado? ");
  handleBool(pet.vacinado);
  printf("\nencontrado na rua? ");
  handleBool(pet.encontradoNaRua);
}

void imprimirPets(PetsRafael *pets, int n, int mesRegistro) {
  int i;
  if (mesRegistro) {
    printf("pets do mes %d\n", mesRegistro);

    for (i = 0; i < n; i++) {
      if (pets[i].dataRegistroPet->m == mesRegistro) {
        imprimirPet(pets[i]);
      }
    }
  } else {
    printf("todos os pets\n");
    for (i = 0; i < n; i++) {
      imprimirPet(pets[i]);
    }
  }
};

void imprimirPetLinha(PetsRafael pet) {
  printf("\n");
  imprimeData(pet.dataRegistroPet);
  printf("\t");
  handleBool(pet.adotado);
  printf("\t\t");
  handleBool(pet.castrado);
  printf("\t\t");
  handleBool(pet.vacinado);
  printf("\t\t");
  handleBool(pet.encontradoNaRua);
}

void imprimirPetsTabela(PetsRafael *pets, int n, int mesRegistro) {
  int i;
  if (mesRegistro) {
    printf("pets do mes %d\n", mesRegistro);

    printf("registro\tadotado\t\tcastrado\tvacinado\tde rua");

    for (i = 0; i < n; i++) {
      if (pets[i].dataRegistroPet->m == mesRegistro) {
        imprimirPetLinha(pets[i]);
      }
    }
  } else {
    printf("todos os pets\n");
    printf("registro\tadotado\t\tcastrado\tvacinado\tde rua");

    for (i = 0; i < n; i++) {
      imprimirPetLinha(pets[i]);
    }
  }
};

void liberaPets(PetsRafael *pets, int n) {
  for (int i = 0; i < n; i++) {
    liberaData(pets[i].dataRegistroPet);
  }

  free(pets);
};

void petsPorMes(PetsRafael *pets, int n) {
  int i, m[12] = {};

  for (i = 0; i < n; i++) {

    if (!pets[i].adotado) {
      m[(pets[i].dataRegistroPet->m) - 1] += 1;
    }
  }

  printf("pets nao adotados por mes de registro\n");

  for (i = 0; i < 12; i++) {
    printf("mes %d: %d\n", i + 1, m[i]);
  }
};

int randBool(int randomNumber) { return randomNumber % 2; }

int randDia(int randomNumber) { return (randomNumber % 30) + 1; }

int randMes(int randomNumber) { return (randomNumber % 12) + 1; }
