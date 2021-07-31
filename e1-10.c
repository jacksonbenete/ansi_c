#include <stdio.h>

/* replace tab, backspace and backslash by visible escape of input */
main()
{
  int c;

  /* This was a tricky one, I had to take a look at stackoverflow,
     that's because any answer involving CONTINUE, ELSE, AND,
     or any other concept not introduced in the book, is not a
     valid answer. And I didn't wanted to put much thought on it. */
  while ((c = getchar()) != EOF) {
    if (c == '\t') { putchar('\\'); c = 't'; }
    if (c == '\b') { putchar('\\'); c = 'b'; }
    if (c == '\\') { putchar('\\'); c = '\\'; }
    putchar(c);
  }
}
