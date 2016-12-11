#include <stdio.h>

main ()
{
     int a, b, mdc;
     
     printf ("a= ");
     scanf ("%i", &a);
     printf ("\nb= ");
     scanf ("%i", &b);
     
     int r;
while (a%b != 0) 
{
 r = a%b;
 a = b;
 b = r;
}
mdc=b;
printf ("\nmdc= %i",b);




getchar();
getchar();
}
