#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank() {
  /* Mengabaikan satu atau beberapa BLANK
     I.S. : currentChar sembarang
     F.S. : currentChar ≠ BLANK atau currentChar = MARK */

  while (currentChar == BLANK && !eot) {
    adv();
  }

  endWord = eot;
}

void startWord() {
  /* I.S. : currentChar sembarang
     F.S. : endWord = true, dan currentChar = MARK;
            atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */
  endWord = false;

  start();
  ignoreBlank();
  advWord();
}

void advWord() {
  /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
     F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin
     MARK Jika currentChar = MARK, endWord = true. Proses : Akuisisi kata
     menggunakan procedure copyWord */

  if (!eot) {
    copyWord();
    ignoreBlank();
  }

  endWord = eot;
}

void copyWord() {
  /* Mengakuisisi kata, menyimpan dalam currentWord
     I.S. : currentChar adalah karakter pertama dari kata
     F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang
     diakuisisi. Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong
   */
  int i = 0;

  currentWord.length = 0;

  while (currentChar != BLANK && !eot && i < CAPACITY) {
    currentWord.contents[i] = currentChar;
    currentWord.length++;
    i++;

    adv();
  }

  if (eot) {
    endWord = true;
  }
}