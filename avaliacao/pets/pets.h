#ifndef PETS_H_INCLUDED
#define PETS_H_INCLUDED

#include <math.h>
typedef struct petsRafael PetsRafael;
typedef struct data Data;

// o que esta comentado é privado.
// não vai permitir outro dev acessar

Data *criarData(int d, int m, int a);
// void imprimeData(Data *d);
// void liberaData(Data *d);

PetsRafael *adicionaPet(PetsRafael *pets, int n, Data *d, int adotado,
                        int castrado, int vacinado, int encontradoNaRua);

// void handleBool(int b);
// void imprimirPet(PetsRafael pet);
void imprimirPets(PetsRafael *pets, int n, int mesRegistro);
void imprimirPetsTabela(PetsRafael *pets, int n, int mesRegistro);

void liberaPets(PetsRafael *pets, int n);
void petsPorMes(PetsRafael *pets, int n);

int randBool(int randomNumber);
int randDia(int randomNumber);
int randMes(int randomNumber);

#endif
