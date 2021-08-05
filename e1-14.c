#include <stdio.h>

#define SIZE 58    /* from 'A' to 'z', size of array */

/* Print a histogram of the frequencies of different
   characters in its input. */
main() {
  int c, i, j;
  int char_list[SIZE];

  for (i = 0; i < SIZE; ++i)
    char_list[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'z')
      char_list[c - 'A'] = char_list[c - 'A'] + 1;
  }

  /* Build histogram. */
  for (i = 0; i < SIZE; ++i) {
    if ('A' + i >= 91 && 'A' + i <= 96)
      ;
    else {
      printf(" %c| ", 'A' + i);
      for (j = 0; j < char_list[i]; ++j)
        printf("#");
      printf("\n");
    }
  }
}
