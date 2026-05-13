#define MAX_TAM 5

typedef struct rafael Rafael;
typedef struct fila Fila;

int verificaFilaCheia(Fila *f);
int verificaFilaVazia(Fila *f);
int verificaCodigoIgual(Fila *f, int codRastreio);

int getInicioFila(Fila *f);

int validaCodigo(Rafael item);

Fila *criaFilaVazia();

int criaChecksum(int codRastreio);
int validaChecksum(int codCompleto);

void enfileira(Fila *f, int codRastreio, float peso, float largura,
               float altura, float comprimento);
void desenfileira(Fila *f);

void encontraItensPorPeso(Fila *f, float peso, int variabilidade);

void imprimeRafael(Rafael item);
void imprimeFila(Fila *f);
void imprimeFilaRecursiva(Fila *f, int indiceAtual, int cont);

void liberaFila(Fila *f);
