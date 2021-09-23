#include <stdio.h>

#include "matrix.h"

int sumSubMatrix(Matrix mat, int m, int i, int j);
int maxSubMatrix(Matrix mat, int m);

int main() {
  int tc;

  scanf("%d", &tc);

  for (int q = 0; q < tc; q++) {
    Matrix m;
    int mm, n;
    scanf("%d", &n);
    readMatrix(&m, n, n);

    scanf("%d", &mm);
    printf("%d\n", maxSubMatrix(m, mm));
  }

  return 0;
}

int sumSubMatrix(Matrix mat, int m, int i, int j) {
  int sum = 0;

  for (int ii = i; ii < i + m; ii++) {
    for (int jj = j; jj < j + m; jj++) {
      sum += ELMT(mat, ii, jj);
    }
  }

  return sum;
}

int maxSubMatrix(Matrix mat, int m) {
  int max = -1;

  for (int i = 0; i <= ROWS(mat) - m; i++) {
    for (int j = 0; j <= COLS(mat) - m; j++) {
      int res = sumSubMatrix(mat, m, i, j);

      if (max < res) {
        max = res;
      }
    }
  }

  return max;
}