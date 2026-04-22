#ifndef ITEMLISTA_H_INCLUDED
#define ITEMLISTA_H_INCLUDED
#define MAXTAM 30

typedef struct item Item;
typedef struct lista Lista;

Lista *criaListaVazia();
void adicionaItemFimLista(Lista *l, int chave);
void adicionaItemQualquerPosicao(Lista *l, int chave, int posicao);
void removeItem(Lista *l, int chave);

int verificaListaVazia(Lista *l);
int verificaListaCheia(Lista *l);

int buscaItemPorChave(Lista *l, int chave);

void imprimeLista(Lista *l);

void liberaLista(Lista *l);

#endif // ITEMLISTA_H_INCLUDED
