#include <stdio.h>

/* print the temperature conversion program
    in reverse order, from 300 to 0. */
main()
{
  int fahr;

  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%3d %6.1f\n", fahr, ((fahr - 32) * (5.0/9.0)));
}
