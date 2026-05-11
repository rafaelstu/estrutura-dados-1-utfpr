#define MAX_TAM 5

typedef struct item Item;
typedef struct fila Fila;

int verificaFilaCheia(Fila *f);
int verificaFilaVazia(Fila *f);
int verificaCodigoIgual(Fila *f, int codRastreio);

int getInicioFila(Fila *f);

int validaCodigo(Item item);

Fila *criaFilaVazia();

int criaChecksum(int codRastreio);
int validaChecksum(int codCompleto);

void enfileira(Fila *f, int codRastreio, float peso, float largura,
               float altura, float comprimento);
void desenfileira(Fila *f);

void encontraItensPorPeso(Fila *f, float peso, int variabilidade);

void imprimeItem(Item item);
void imprimeFila(Fila *f);
void imprimeFilaRecursiva(Fila *f, int indiceAtual, int cont);

void liberaFila(Fila *f);
