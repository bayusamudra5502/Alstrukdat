#include <stdio.h>

#include "prioqueue.h"

ElType readData() {
  ElType res;

  scanf("%d", &res.tArrival);
  scanf("%d", &res.id);
  scanf("%d", &res.score);
  scanf("%d", &res.dService);

  return res;
}

void printData(int layani, int id, int waktuMenunggu) {
  printf("%d %d %d\n", layani, id, waktuMenunggu);
}

int main() {
  PrioQueue pq;
  CreatePrioQueue(&pq);

  int n, t = 1;
  scanf("%d", &n);

  if (n <= 0) {
    printf("Tidak ada layanan\n");
    return 0;
  }

  for (int i = 0; i < n; i++) {
    ElType input = readData();

    if (t <= input.tArrival) {
      ElType layan;

      if (isEmpty(pq)) {
        layan = input;
        t = layan.tArrival;
        printData(t, layan.id, 0);
        t += layan.dService;
      } else {
        while (!isEmpty(pq) && t <= input.tArrival) {
          ElType antrian;

          dequeue(&pq, &antrian);
          printData(t, antrian.id, t - antrian.tArrival);
          t += antrian.dService;
        }

        if (t <= input.tArrival) {
          t = input.tArrival;
          printData(t, input.id, 0);
          t += input.dService;
        } else {
          enqueue(&pq, input);
        }
      }

    } else {
      enqueue(&pq, input);
    }
  }

  while (!isEmpty(pq)) {
    ElType antrian;

    dequeue(&pq, &antrian);
    printData(t, antrian.id, t - antrian.tArrival);
    t += antrian.dService;
  }

  return 0;
}