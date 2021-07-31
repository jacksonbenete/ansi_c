#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = 0, 10, ..., 100; */

main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 100;
  step = 10;

  celsius = lower;

  while(celsius <= upper) {
    fahr = 32 + (9.0/5.0) * celsius;
    printf("%3.0f %6.2f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
