#include <stdio.h>

#include "queue.h"

float avgElmt(Queue Q);

int main() {
  Queue q;
  boolean isDone = false;

  CreateQueue(&q);

  while (!isDone) {
    int command, val;
    scanf("%d", &command);

    switch (command) {
      case 1:
        scanf("%d", &val);

        if (!isFull(q)) {
          enqueue(&q, val);
        } else {
          printf("Queue penuh\n");
        }

        break;
      case 2:
        if (!isEmpty(q)) {
          dequeue(&q, &val);
        } else {
          printf("Queue kosong\n");
        }
        break;
      case 0:
        isDone = true;
        break;
    }
  }

  printf("%d\n", length(q));
  if (length(q) > 0) {
    float avg = avgElmt(q);
    printf("%.2f\n", avg);
  } else {
    printf("Tidak bisa dihitung\n");
  }

  return 0;
}

float avgElmt(Queue Q) {
  /* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */

  int sum = 0;
  int len = 0;

  while (!isEmpty(Q)) {
    int tmp;
    dequeue(&Q, &tmp);

    sum += tmp;
    len++;
  }

  return sum / (float)len;
}