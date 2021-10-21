#include <math.h>
#include <stdio.h>

#include "stack.h"
#include "tokenmachine.h"

void printStack(Stack s) {
  printf("[");

  for (int i = 0; i <= s.idxTop; i++) {
    printf("%d", (char)s.buffer[i]);
    if (i != s.idxTop) {
      printf(",");
    }
  }

  printf("]\n");
}

int main() {
  boolean isExprExist = false;
  Stack expr;
  CreateStack(&expr);

  startToken();

  isExprExist = !endToken;

  while (!endToken) {
    if (currentToken.tkn == 'b') {
      push(&expr, currentToken.val);
      printf("%d\n", currentToken.val);
    } else {
      int val1, val2, res;

      pop(&expr, &val2);
      pop(&expr, &val1);

      printf("%d %c %d\n", val1, currentToken.tkn, val2);

      switch (currentToken.tkn) {
        case '+':
          res = val1 + val2;
          break;
        case '-':
          res = val1 - val2;
          break;
        case '*':
          res = val1 * val2;
          break;
        case '/':
          res = val1 / val2;
          break;
        case '^':
          res = pow(val1, val2);
          break;
      }

      push(&expr, res);
      printf("%d\n", res);
    }

    advToken();
  }

  if (isExprExist) {
    int res;
    pop(&expr, &res);

    printf("Hasil=%d\n", res);
  } else {
    printf("Ekspresi kosong\n");
  }

  return 0;
}