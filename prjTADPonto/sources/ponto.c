#include "ponto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ponto {
  float x;
  float y;
};

Ponto *criaPonto(float x, float y) {
  Ponto *p = malloc(sizeof(Ponto));
  p->x = x;
  p->y = y;
  return p;
};

void imprimePonto(Ponto *p) { printf("x: %.2f, y: %.2f\n", p->x, p->y); }

float calculaDistancia(Ponto *p1, Ponto *p2) {
  // distancia euclidiana, raiz quadrada do quadrado da diferença
  // entre os campos x + o quadrado da diferença entre os campos y

  float dx, dy;

  dx = p2->x - p1->x;
  dy = p2->y - p1->y;

  return sqrt(pow(dx, 2) + pow(dy, 2));
};

void liberaPonto(Ponto *p) { free(p); }
