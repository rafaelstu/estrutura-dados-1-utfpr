#ifndef ITEMDEQUE_H_INCLUDED
#define ITEMDEQUE_H_INCLUDED

#define MAXTAM 5

typedef struct duracao Duracao;
typedef struct rafaelMusicasLegais RafaelMusicasLegais;
typedef struct deque Deque;

Deque *criaDeque();
int dequeCheia(Deque *dq);
int dequeVazia(Deque *dq);
int insereFinalDeque(Deque *dq, int chave, char *musica, int bpm, int m, int s);
int insereInicioDeque(Deque *dq, int chave, char *musica, int bpm, int m,
                      int s);
int removeInicioDeque(Deque *dq);
int removeFinalDeque(Deque *dq);

void calculaTotalDuracao(Deque *dq);

void imprimeDeque(Deque *dq);
void imprimeItem(RafaelMusicasLegais m);
void liberaDeque(Deque *dq);

#endif // ITEMDEQUE_H_INCLUDED
