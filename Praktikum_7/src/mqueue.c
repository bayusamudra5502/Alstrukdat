#include <stdio.h>

#include "queue.h"

int main() {
  Queue q;

  CreateQueue(&q);
  printf("Length: %d\n", length(q));
  printf("isEmpty: %d\n\n", isEmpty(q));

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  enqueue(&q, 40);
  enqueue(&q, 50);
  printf("Length: %d\n", length(q));
  displayQueue(q);
  printf("\n");

  int val;
  dequeue(&q, &val);
  printf("val: %d\n", val);
  printf("Length: %d\n\n====", length(q));

  enqueue(&q, 60);

  for (int i = 0; i < 5; i++) {
    dequeue(&q, &val);
    printf("val: %d\n", val);
    printf("Length: %d\n\n", length(q));
  }

  displayQueue(q);

  return 0;
}