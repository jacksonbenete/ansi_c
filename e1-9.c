#include <stdio.h>

/* replace multiple blanks by a single blank of a input */
main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      while ((c = getchar()) == ' ')
        ;
      putchar(' ');
    }
    putchar(c);
}
}
