#include <stdio.h>

#include "wordmachine.h"

int main() {
  printf("Halo, DUnia\n");
  startWord();

  while (!endWord) {
    printf("Kata sekarang : %s\n", currentWord.contents);
    printf("Panjangnya : %d\n", currentWord.length);
    printf("=== STATUS ===\n");
    printf("endWord: %d\n", endWord);
    printf("eot: %d\n", eot);
    printf("endWord: %d\n", currentChar);
    printf("\n");

    advWord();
  }

  printf("Kata sekarang : %s\n", currentWord.contents);
  printf("Panjangnya : %d\n", currentWord.length);
  printf("=== STATUS ===\n");
  printf("endWord: %d\n", endWord);
  printf("eot: %d\n", eot);
  printf("endWord: %d\n", currentChar);
  printf("\n");

  return 0;
}