#define MAX_TAM 5

typedef struct item Item;
typedef struct fila Fila;

int verificaFilaCheia(Fila *f);
int verificaFilaVazia(Fila *f);

Fila *criaFilaVazia();

void enfileira(Fila *f, int chave);
void desenfileira(Fila *f);
void imprimeFila(Fila *f);
void liberaFila(Fila *f);
