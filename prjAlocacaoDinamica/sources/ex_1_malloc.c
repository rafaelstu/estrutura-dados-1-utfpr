#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int t = 50, i;
  int *v;

  srand(time(NULL));

  v = malloc(t * sizeof(int));

  for (i = 0; i < t; i++) {
    v[i] = (rand() % 100) + 1;
    printf("p%d: %d\n", i, v[i]);
  }

  free(v);
  return 0;
}
