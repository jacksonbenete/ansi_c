#include <stdio.h>

#define SIZE 100 /* max line size of input */

int parseline(char line[], int c);
void reverse(char line[]);

/* Reverses each line received from input.
 
   BUGS: we don't know how to create a dynamic array,
         so we can only parse a limited size line.*/
main()
{
  int c;
  char line[SIZE];
  
  while ((c = getchar()) != EOF) {
    c = parseline(line, c);
    reverse(line);
    
    printf("%s", line);
  }
  
  return 0;
}

/* parse the line up to size limit, returning when the size
   is reached or when we encounter a newline */
int parseline(char line[], int c)
{
  int i;
  
  for (i = 0; i < SIZE - 1 && c != EOF; ++i) {
    line[i] = c;
    
    if (c == '\n') {
      line[i+1] = '\0';
      return i;
    }
    
    c = getchar();
  }
  line[i] = '\0';
  return i;
}

void reverse(char old[])
{
  int i, j, len;
  char new[SIZE];
  
  /* get to know the size of string old[]*/
  for (i = 0; old[i] != '\0'; ++i)
    new[i] = old[i];
  len = i;
  
  /* reverse up to len-1 so we can exclude the '\0' char */
  for (i = 0, j = len-1; i < len; ++i, --j)
  {
    new[i] = old[j];
  }
  
  /* we can't return the new array (we still don't know how to)
     so we must overwrite the original */
  for (i = 0; old[i] != '\0'; ++i)
    old[i] = new[i];
}
