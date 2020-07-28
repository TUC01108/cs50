#include <stdio.h>

int getline();

int main(void)
{
    char line[100];
	getline(&line[0], 100);
}



int getline(char *line, int max)
{
int nch = 0;
int c;
max = max - 1;			/* leave room for '\0' */

#ifndef FGETLINE
while((c = getchar()) != EOF)
#else
while((c = getc(fp)) != EOF)
#endif
	{
	if(c == '\n')
		break;

	if(nch < max)
		{
		*(line + nch) = c;
		nch = nch + 1;
		}
	}

if(c == EOF && nch == 0)
	return EOF;

*(line + nch) = '\0';
return nch;
}