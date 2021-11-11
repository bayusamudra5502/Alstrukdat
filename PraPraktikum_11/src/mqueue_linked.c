#include <stdio.h>

#include "queue_linked.h"

void print_queue(Queue q) {
  Address p = ADDR_HEAD(q);

  printf("[");

  while (p) {
    if (p != ADDR_HEAD(q)) {
      printf(",");
    }

    printf("%d", INFO(p));
    p = NEXT(p);
  }

  printf("]");
}

int main() {
  Queue q;
  CreateQueue(&q);

  printf("Length 0 : %d - %d\n", length(q), isEmpty(q));

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);

  print_queue(q);
  printf("\nLength 1 : %d - %d\n", length(q), isEmpty(q));

  int val;
  dequeue(&q, &val);
  printf("%d\n", val);
  dequeue(&q, &val);
  dequeue(&q, &val);

  print_queue(q);
  printf("\n");

  dequeue(&q, &val);
  dequeue(&q, &val);

  printf("Length 0 : %d - %d", length(q), isEmpty(q));

  return 0;
}