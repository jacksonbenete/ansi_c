#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int gline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = gline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)    /* there was a line */
    printf("length: %d\nline: %s\n", max, longest);
  return 0;
}

/* gline: read a line into s, return length */
int gline(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  /* at this point the program either found EOF, '\n',
     or reached it's limit (i < lim-1), if we want to
     know the real lenght we should keep counting */
  if (c != EOF && c != '\n')
    while ((c = getchar()) != EOF && c != '\n')
      ++i;
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
