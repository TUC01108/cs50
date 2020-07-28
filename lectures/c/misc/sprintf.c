#define M_PI 3.14159265358979323846
#include <stdio.h>

int main () {
   char str[80];

   sprintf(str, "Value of Pi = %f", M_PI);
   puts(str);

   return(0);
}