#include <stdio.h>

int main() {
  int v[5] = {3, -7, 5, 0, 4};
  int *p = v;

  *p = 10;
  *(p + 1) = *(p + 1) + 5;
  *(p + 3) = 10;

  for (int i = 0; i < 5; i++) {
    printf("%d\t", p[i]);
  }

  return 0;
}
