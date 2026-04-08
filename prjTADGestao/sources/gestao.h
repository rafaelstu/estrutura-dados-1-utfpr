#ifndef GESTAO_H_INCLUDED
#define GESTAO_H_INCLUDED

typedef struct pessoa Pessoa;
typedef struct data Data;
typedef struct servico Servico;

Data *dataNova(int d, int m, int a);
void imprimeData(Data *d);
void liberaData(Data *d);

Pessoa *adicionaServico(Pessoa *vet, int n, char nome[], float valor);
void imprimeServicos(Servico *vet, int n);
int getQtdServico(Pessoa *vet, int n);
void liberaServicos(Servico *vet);

Pessoa *adicionaPessoa(Pessoa *vet, char nome[], Data *d, int n);
void imprimePessoas(Pessoa *vet, int n);
void liberaPessoas(Pessoa *vet, int n);

#endif
