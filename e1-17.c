#include <stdio.h>

#define SIZE 80

int parseline(int c, char line[], int i);

/* print all input lines that are longer than 80 characters from
   standard input, this version should accept <, | or manual entry */
main()
{
  int c, len;
  char line[SIZE];

  while ((c = getchar()) != EOF) {
    len = parseline(c, line, 0);
    
    if (len > SIZE)
      printf("%s (...)\n", line);
  }
  return 0;
}

/* parse line to detect linebreak and size */
int parseline(int c, char line[], int i)
{
  while (c != EOF && c != '\n') {
    if (i < SIZE)
      line[i] = c;
    ++i;
    c = getchar();
  }
  return i;
}
