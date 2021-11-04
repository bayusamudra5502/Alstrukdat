#include <stdio.h>

#include "list_circular.h"

void deleteProcess(List *l, ElType tQ);
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai
aturan round robin, yaitu:
- jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan
INFO(last)=INFO(last)-tQ
- jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */

float average(List l);
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */

void addProcess(List *l);
void calculateAvg(List l);

int main() {
  List process;
  CreateList(&process);

  int tQ;
  do {
    scanf("%d", &tQ);
  } while (tQ <= 0);

  char cmd[10];
  do {
    scanf("%s", cmd);

    switch (cmd[0]) {
      case 'A':
        addProcess(&process);
        break;

      case 'D':
        deleteProcess(&process, tQ);
        break;

      case 'F':
        calculateAvg(process);
        break;

      default:
        printf("Kode salah\n");
        break;
    }
  } while (cmd[0] != 'F');

  return 0;
}

void calculateAvg(List l) {
  float avg = average(l);
  if (avg < 0) {
    printf("Proses selesai\n");
  } else {
    printf("%.2f\n", avg);
  }
}

void addProcess(List *l) {
  ElType val;
  scanf("%d", &val);

  if (val > 0) {
    insertFirst(l, val);
  }
}

void deleteProcess(List *l, ElType tQ) {
  if (isEmpty(*l)) {
    printf("List kosong\n");
  } else {
    ElType lastData;
    deleteLast(l, &lastData);
    printf("%d\n", lastData < tQ ? lastData : tQ);

    if (lastData > tQ) {
      insertFirst(l, lastData - tQ);
    }
  }
}

float average(List l) {
  if (isEmpty(l)) {
    return -1;
  } else {
    int sum = 0, len = 0;
    Address a = FIRST(l);

    do {
      sum += INFO(a);
      len++;
      a = NEXT(a);
    } while (a != FIRST(l));

    return ((float)sum) / len;
  }
}