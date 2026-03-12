#include <stdio.h>

typedef struct pedido Pedido;

struct pedido {
  char nomeCliente[30];
  char descPedido[50];
  float valorPedido;
};

int main() {
  Pedido p;

  printf("informe o nome do cliente: ");
  scanf("%[^\n]s", p.nomeCliente);

  printf("informe o pedido do cliente: ");
  scanf("%[^\n]s", p.descPedido);

  printf("informe o valor do pedido: ");
  scanf("%f", &p.valorPedido);

  printf("cliente: %s", p.nomeCliente);
  printf("pedido: %s", p.descPedido);
  printf("valor: %.2f", p.valorPedido);

  return 0;
}
