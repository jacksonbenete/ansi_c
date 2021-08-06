#include <stdio.h>

float fahr2celsius(int fahr);

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
main()
{
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  while (lower <= upper) {
    printf("%d\t%6.1f\n", lower, fahr2celsius(lower));
    lower = lower + step;
  }
}

/* convert Fahrenheit to Celsius */
float fahr2celsius(int fahr)
{
  float celsius;

  celsius = (5.0/9.0) * (fahr - 32.0);
  return celsius;
}
