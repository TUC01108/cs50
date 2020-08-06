#include <stdio.h>
#define  MAX_LEN  60
 
int main(void)
{
   FILE *stream;
   fpos_t pos;
   char line1[MAX_LEN];
   char line2[MAX_LEN];
   char *result;
   char ch;
   int num;
 
   /* The following call opens a text file for reading.   */
   if ((stream = fopen("/Users/patriciawinter/Desktop/cs50/lectures/lecture5/c/mylib/myfile.text", "r")) == NULL)
      printf("Could not open data file\n");
   else if ((result = fgets(line1,MAX_LEN,stream)) != NULL)
           {
            printf("The string read from myfile: %s\n", result);
            fclose(stream);
           }
 
   /* The following call opens a fixed record length file */
   /* for reading and writing.                            */
   if ((stream = fopen("/Users/patriciawinter/Desktop/cs50/lectures/lecture5/c/mylib/myfile2.text", "rb+, lrecl=80,  \
                 blksize=240, recfm=f")) == NULL)
         printf("Could not open data file\n");
   else {
         fgetpos(stream, &pos);
         if (!fread(line2,sizeof(line2),1,stream))
            perror("fread error");
         else printf("1st record read from myfile2: %s\n", line2);
 
         fsetpos(stream, &pos);     /* Reset pointer to start of file */
         fputs(result, stream);     /* The line read from myfile is   */
                                    /* written to myfile2.            */
         fclose(stream);
        }
}