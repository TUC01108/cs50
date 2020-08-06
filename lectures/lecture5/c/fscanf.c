#include <stdio.h>
 
#define  MAX_LEN  80
 
int main(void)
{
   FILE *stream;
   long l;
   float fp;
   char s[MAX_LEN + 1];
   char c;
 
   stream = fopen("/Users/patriciawinter/Desktop/cs50/lectures/lecture5/c/mylib/myfile3.text", "r");
 
   /* Put in various data. */
 
   fscanf(stream, "%s", &s [0]);
   fscanf(stream, "%ld", &l);
   fscanf(stream, "%c", &c);
   fscanf(stream, "%f", &fp);
 
   printf("string = %s\n", s);
   printf("long double = %ld\n", l);
   printf("char = %c\n", c);
   printf("float = %f\n", fp);
}
 
/***************  If myfile contains  ************************
**************** abcdefghijklmnopqrstuvwxyz 343.2 ***********
**********************  expected output is:  *********************
 
string = abcdefghijklmnopqrstuvwxyz
long double = 343
char = .
float = 2.000000
*/