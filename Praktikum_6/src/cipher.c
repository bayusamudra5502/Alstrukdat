#include <stdio.h>

#include "wordmachine.h"

int geser = 0;

void chiper(char* str, int len) {
  for (int i = 0; i < len; i++) {
    char result;
    result = ((str[i] - 'A' + geser) % 26) + 'A';
    printf("%c", result);
  }
}

void encryptWord() {
  chiper(currentWord.contents, currentWord.length);

  if (!eot) {
    printf(" ");
  }
}

int main() {
  startWord();
  geser = currentWord.length;

  while (!endWord) {
    encryptWord();
    advWord();
  }

  printf(".\n");

  return 0;
}