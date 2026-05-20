#include "itemDeque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct duracao {
  int minutos;
  int segundos;
};

struct rafaelMusicasLegais {
  int chave;
  char *musica;
  Duracao *duracao;
  int bpm;
};

struct deque {
  RafaelMusicasLegais itens[MAXTAM];
  int inicio;
  int fim;
  int qtd;
};

Duracao *criaDuracao(int m, int s) {
  Duracao *d = (Duracao *)malloc(sizeof(Duracao));

  d->minutos = m;
  d->segundos = s;

  return d;
}

Deque *criaDeque() {
  Deque *dq;
  dq = (Deque *)malloc(sizeof(Deque));
  dq->inicio = 0;
  dq->fim = 0;
  dq->qtd = 0;
  return dq;
}

int dequeCheia(Deque *dq) { return (dq->qtd == MAXTAM); }

int dequeVazia(Deque *dq) { return (dq->qtd == 0); }

int insereFinalDeque(Deque *dq, int chave, char *musica, int bpm, int m,
                     int s) {
  if (dequeCheia(dq) != 0) {
    printf("\nErro: Nao foi possivel inserir, playlist cheia ou erro.\n");
    return 0;
  }

  RafaelMusicasLegais novoItem;

  novoItem.duracao = criaDuracao(m, s);
  novoItem.chave = chave;
  novoItem.musica = (char *)malloc((strlen(musica) + 1) * sizeof(char));
  strcpy(novoItem.musica, musica);
  novoItem.bpm = bpm;
  dq->itens[dq->fim] = novoItem;
  dq->fim = (dq->fim + 1) % MAXTAM;
  dq->qtd++;
  return 1;
}

int insereInicioDeque(Deque *dq, int chave, char *musica, int bpm, int m,
                      int s) {
  if (dequeCheia(dq) != 0) {
    printf("\nErro: Nao foi possivel inserir, playlist cheia ou erro.\n");
    return 0;
  }

  dq->inicio--;
  if (dq->inicio < 0) {
    dq->inicio = MAXTAM - 1;
  }

  RafaelMusicasLegais novoItem;

  novoItem.duracao = criaDuracao(m, s);
  novoItem.chave = chave;
  novoItem.musica = (char *)malloc((strlen(musica) + 1) * sizeof(char));
  strcpy(novoItem.musica, musica);
  novoItem.bpm = bpm;
  dq->itens[dq->inicio] = novoItem;
  dq->qtd++;
  return 1;
}

int removeInicioDeque(Deque *dq) {
  if (dequeVazia(dq) != 0) {
    printf("\nErro: Nao foi possivel remover, deque vazia ou erro.\n");
    return 0;
  }
  dq->inicio = (dq->inicio + 1) % MAXTAM;
  dq->qtd--;
  return 1;
}

int removeFinalDeque(Deque *dq) {
  if (dequeVazia(dq) != 0) {
    printf("\nErro: Nao foi possivel remover, deque vazia ou erro.\n");
    return 0;
  }
  dq->fim--;
  if (dq->fim < 0) {
    dq->fim = MAXTAM - 1;
  }
  dq->qtd--;
  return 1;
}

void imprimeItem(RafaelMusicasLegais m) {
  printf("\nnome: %s\n", m.musica);
  printf("%02d:%02d", m.duracao->minutos, m.duracao->segundos);
  printf(" | %d BPM\n", m.bpm);
}

void imprimeDeque(Deque *dq) {
  int i = dq->inicio;
  for (int n = 0; n < dq->qtd; n++) {
    imprimeItem(dq->itens[i]);
    i = (i + 1) % MAXTAM;
  }
}
void liberaDuracao(Duracao *d) { free(d); }
void somaDuracao(Duracao *d, int m, int s) {
  d->minutos += m;
  d->segundos += s;

  d->minutos += d->segundos / 60;
  d->segundos = d->segundos % 60;
}

void calculaDuracao(Deque *dq, int i, int tam, Duracao *d, Duracao *dL,
                    Duracao *dA) {

  if (tam == 0) {
    return;
  }

  int bpm = dq->itens[i].bpm;
  int m = dq->itens[i].duracao->minutos;
  int s = dq->itens[i].duracao->segundos;

  somaDuracao(d, m, s);
  if (bpm >= 120) {
    somaDuracao(dA, m, s);
  } else {
    somaDuracao(dL, m, s);
  }

  calculaDuracao(dq, (i + 1) % MAXTAM, tam - 1, d, dL, dA);
}

void calculaTotalDuracao(Deque *dq) {
  int i = dq->inicio;
  int totalMinutos, totalSegundos;
  int animadaMinutos, animadaSegundos;
  int lentaMinutos, lentaSegundos;

  Duracao *d = criaDuracao(0, 0);
  Duracao *dL = criaDuracao(0, 0);
  Duracao *dA = criaDuracao(0, 0);

  calculaDuracao(dq, i, dq->qtd, d, dL, dA);

  totalMinutos = d->minutos;
  totalSegundos = d->segundos;

  animadaMinutos = dA->minutos;
  animadaSegundos = dA->segundos;

  lentaMinutos = dL->minutos;
  lentaSegundos = dL->segundos;

  printf("\nDuração total: %02d:%02d", totalMinutos, totalSegundos);
  printf("\nDuração animadas: %02d:%02d", animadaMinutos, animadaSegundos);
  printf("\nDuração lentas: %02d:%02d\n", lentaMinutos, lentaSegundos);

  liberaDuracao(d);
  liberaDuracao(dL);
  liberaDuracao(dA);
}

void liberaDeque(Deque *dq) {
  int i = dq->inicio;
  for (int n = 0; n < dq->qtd; n++) {
    liberaDuracao(dq->itens[i].duracao);
    i = (i + 1) % MAXTAM;
  }

  free(dq);
}
