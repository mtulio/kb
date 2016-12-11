#include <stdio.h>
main () {
     int x, y;
     
     for (x=0, y=0; x+y<10; ++x) {
     
     y = getchar();
     y = y-'0'; 
     printf ("%d", y);    
     getchar();
     getchar();
}
}
