#include <stdio.h>

#include "tokenmachine.h"

int main() {
  printf("Halo, dunia\n");
  startToken();

  while (!endToken) {
    printf("tkn : %c\n", currentToken.tkn);
    printf("val : %d\n", currentToken.val);
    printf("=== STATUS ===\n");
    printf("endToken: %d\n", endToken);
    printf("eot: %d\n", eot);
    printf("currentChar: %c\n", currentChar);
    printf("\n");
    // printf("<'%c',%d>\n", currentToken.tkn, currentToken.val);

    advToken();
  }

  // printf("<'%c',%d>\n", currentToken.tkn, currentToken.val);

  printf("tkn : %c\n", currentToken.tkn);
  printf("val : %d\n", currentToken.val);
  printf("=== STATUS ===\n");
  printf("endToken: %d\n", endToken);
  printf("eot: %d\n", eot);
  printf("currentChar: %c\n", currentChar);
  printf("\n");

  return 0;
}