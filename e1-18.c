#include <stdio.h>

#define SIZE 80  /* size of line to be parsed */

int parseline(char line[], int c);

/* remove trailing spaces, tabs and blank lines from input */
main()
{
  int c, i;
  char line[SIZE];
  
  while ((c = getchar()) != EOF) {
    c = parseline(line, c);
    
    for (i = 0; i < SIZE && line[i] != '\0'; ++i)
      printf("%c", line[i]);
  }
  
  return 0;
}

/* parse line counting and overwriting trailing spaces and empty lines */
int parseline(char line[], int c) {
  int i, j;
  char last;
  
  last = c;
  j = 0;
  for (i = 0; i < SIZE - 1 && c != EOF; ++i) {
    line[i] = c;
    
    /* if first character is a newline, line is blank,
       we just ignore the line in order to delete it. */
    if (line[0] == '\n') {
      line[0] = '\0';
      return i;
    }
    
    /* when we detect a new line, we stop parsing the line and
       if there is trailing spaces we return to it and overwrite them. */
    if (c == '\n') {
      i = i-j;
      line[i] = '\n';
      line[i+1] = '\0';
      return i;
    }
    
    /* if last char was space/tab, and we found another space/tab
       start counting how many spaces we have in line[]. */
    if (c == ' ' || c == '\t')
      ++j;
    else
      j = 0;
    
    last = c;
    c = getchar();
  }
  
  /* if we didn't returned before, it means that the line is
     greater than SIZE, so we need to return what we have and
     keep parsing the line later. */
  line[i+1] = '\0';
  return i;
}
