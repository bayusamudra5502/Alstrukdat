#include <stdio.h>

#include "stack.h"

boolean carry = false;
Stack result[2];

int sumChar(int a, int b) {
  int ia = a - '0';
  int ib = b - '0';
  int result = ia + ib + carry;

  if (result > 9) {
    carry = true;
  } else {
    carry = false;
  }

  return (result % 10) + '0';
}

void pushResult(int hasil) {
  if (!isFull(result[0])) {
    push(&result[0], hasil);
  } else {
    push(&result[1], hasil);
  }
}

int popResult() {
  int hasil;

  if (!isEmpty(result[1])) {
    pop(&result[1], &hasil);
  } else {
    pop(&result[0], &hasil);
  }

  return hasil;
}

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

void debugStack(Stack s1, Stack s2) {
  printf("Stack s1: ");
  printStack(s1);

  printf("Stack s2: ");
  printStack(s2);
}

int main() {
  Stack s1, s2;
  CreateStack(&s1);
  CreateStack(&s2);
  CreateStack(&result[0]);
  CreateStack(&result[1]);

  unsigned char cc;

  do {
    scanf("%c", &cc);
    if (cc != '#') {
      push(&s1, (ElType)cc);
    }
  } while (cc != '#');

  scanf("%c", &cc);

  do {
    scanf("%c", &cc);
    if (cc != '#') {
      push(&s2, (ElType)cc);
    }
  } while (cc != '#');

  int op1, op2;
  while (!isEmpty(s1) && !isEmpty(s2)) {
    pop(&s1, &op1);
    pop(&s2, &op2);

    pushResult(sumChar(op1, op2));
  }

  while (!isEmpty(s1)) {
    int op1;
    pop(&s1, &op1);
    pushResult(sumChar(op1, '0'));
  }

  while (!isEmpty(s2)) {
    int op2;
    pop(&s2, (ElType*)&op2);
    pushResult(sumChar(op2, '0'));
  }

  if (carry) {
    pushResult('1');
  }

  while (!isEmpty(result[0]) || !isEmpty(result[1])) {
    printf("%c", popResult());
  }

  printf("\n");

  return 0;
}
