/* exp example */
#include <stdio.h>
#include <math.h>

int main ()
{
  double param, result;
  param = 5.0;
  result = exp (param);
  printf ("The exponential value of %lf is %lf.\n", param, result );
  getchar();
  getchar();
  return 0;
}
