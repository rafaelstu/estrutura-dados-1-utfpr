#include <stdio.h>
#include <string.h>

int compara_string(char *sa, char *sb) {
  if (strlen(sa) > strlen(sb))
    return 1;
  if (strlen(sa) < strlen(sb))
    return 1;

  while (*sa != '\0') {
    if (*sa != *sb)
      return 1;
    sa++;
    sb++;
  }

  return 0;
};

int main() {
  char sa[30] = "bom dia";
  char sb[15] = "bom dia";

  if (compara_string(sa, sb)) {
    printf("string difereten");
  } else {
    printf("string igual");
  };

  return 0;
}
