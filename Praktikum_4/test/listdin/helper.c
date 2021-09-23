#include <string.h>

#include "../../src/listdin.h"
#include "test.h"

ListDin createHelper(int capacity, int* array, int n) {
  ListDin res;
  CreateListDin(&res, capacity);

  for (int i = 0; i < n; i++) {
    res.buffer[i] = array[i];
  }

  res.nEff = n;
  return res;
}

boolean isEqHelper(ListDin arr1, ListDin arr2) {
  if (arr1.nEff == arr2.nEff) {
    return memcmp(arr1.buffer, arr2.buffer, arr1.nEff * sizeof(int)) == 0;
  } else {
    return false;
  }
}

boolean isAllEqHelper(ListDin arr1, ListDin arr2) {
  return arr1.capacity == arr2.capacity && isEqHelper(arr1, arr2);
}

void copyFromArrayHelper(int n, int* arr, ListDin* l) {
  for (int i = 0; i < n; i++) {
    l->buffer[i] = arr[i];
  }

  l->nEff = n;
}