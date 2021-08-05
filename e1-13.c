#include <stdio.h>

#define SIZE 19    /* max size of word, size of array */

/* Creates a histogram of the frequency of the size of
   words on input. */
/* BUGS: It's not necessary a bug but to avoid increasing the code
         complexity (introducing more if statements) we're counting
         sequential linebreaks like word_list[0] increments. */
main()
{
  int c, i, j, word_count;
  int word_list[SIZE + 1];

  word_count = 0;
  for (i = 0; i < SIZE; ++i)
    word_list[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (word_count > SIZE)
        word_count = SIZE;
      word_list[word_count] = word_list[word_count] + 1;
      word_count = 0;
    }
    else
      ++word_count;
  }

  /* We still don't know how to create functions other than main(),
     so here we will parse the list and print the histogram. */
  for (i = 1; i < SIZE; ++i) {
    if (i == SIZE - 1) printf(" %d+| ", SIZE - 1);
    else printf(" %3d| ", i);

    for (j = 0; j < word_list[i]; ++j)
      printf("#");
    printf("\n");
  }
}
