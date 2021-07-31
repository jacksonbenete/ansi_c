#include <stdio.h>

/* count blanks, tabs and newlines of input */
main()
{
  int c, b, t, nl;
  b = 0;
  t = 0;
  nl = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ') ++b;
    if (c == '\t') ++t;
    if (c == '\n') ++nl;
  }
  printf("blanks %d\t tabs %d\t newlines %d\n", b, t, nl);
}
