#include <stdio.h>

#include "queue_linked.h"

int main() {
  Queue q;
  CreateQueue(&q);

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int time;
    scanf("%d", &time);

    while (!isEmpty(q) && HEAD(q) < time - 300) {
      int tmp;
      dequeue(&q, &tmp);
    }

    enqueue(&q, time);
    printf("%d\n", length(q));
  }

  return 0;
}