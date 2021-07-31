#include <stdio.h>

/* prints one word per line from input */
main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      putchar('\n');
      while ((c = getchar()) == ' ')
        ;
    }
    if (c == '\t')
      putchar('\n');
    else if (c == '\n')
      ;
    else
      putchar(c);
  }
}
