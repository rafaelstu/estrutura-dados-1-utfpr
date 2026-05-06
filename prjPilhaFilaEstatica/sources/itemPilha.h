#ifndef ITEMPILHA_H_INCLUDED
#define ITEMPILHA_H_INCLUDED

#define MAX_TAM 10

typedef struct item Item;
typedef struct pilha Pilha;

Pilha *criaPilhaVazia();
Pilha *invertePilha(Pilha *p);

int verificaPilhaCheia(Pilha *p);
int verificaPilhaVazia(Pilha *p);
int verificaPilhaIgual(Pilha *p1, Pilha *p2);

void empilha(Pilha *p, char chave);
void desempilha(Pilha *p);
void imprimePilha(Pilha *p);
void liberaPilha(Pilha *p);

#endif // ITEMPILHA_H_INCLUDED
