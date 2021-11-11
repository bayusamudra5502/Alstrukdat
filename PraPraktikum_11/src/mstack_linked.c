#include <stdio.h>

#include "stack_linked.h"

void print_stack(Stack q) {
  Address p = ADDR_TOP(q);

  printf("[");

  while (p) {
    if (p != ADDR_TOP(q)) {
      printf(",");
    }

    printf("%d", INFO(p));
    p = NEXT(p);
  }

  printf("]");
}

int main() {
  Stack s;
  CreateStack(&s);

  printf("isEmpty : %d\n", isEmpty(s));

  push(&s, 1);
  push(&s, 2);
  push(&s, 3);
  push(&s, 4);
  push(&s, 5);

  print_stack(s);
  printf("\n");

  printf("isEmpty : %d\n", isEmpty(s));

  int val;
  pop(&s, &val);
  pop(&s, &val);
  printf("%d\n", val);
  pop(&s, &val);
  print_stack(s);

  pop(&s, &val);
  pop(&s, &val);

  printf("\nisEmpty : %d\n", isEmpty(s));

  return 0;
}