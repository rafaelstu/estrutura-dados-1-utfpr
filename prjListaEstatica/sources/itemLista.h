#ifndef ITEMLISTA_H_INCLUDED
#define ITEMLISTA_H_INCLUDED
#define MAXTAM 5

typedef struct item Item;
typedef struct lista Lista;

Lista *criaListaVazia();

int verificaListaVazia(Lista *l);
int verificaListaCheia(Lista *l);
void adicionaItemFimLista(Lista *l, int chave);
void imprimeLista(Lista *l);
int buscaItemPorChave(Lista *l, int chave);
void removeItem(Lista *l, int chave);
void liberaLista(Lista *l);

#endif // ITEMLISTA_H_INCLUDED
