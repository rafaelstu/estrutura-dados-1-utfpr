#include <stdio.h>
#include <stdlib.h>

int main() {
  int t = 50, i;
  int *v;

  v = calloc(t, sizeof(int));

  for (i = 0; i < t; i++) {
    v[i] = 2820994;
    printf("p%d: %d\n", i, v[i]);
  }

  free(v);
  return 0;
}
