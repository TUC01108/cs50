#include <stddef.h>
#include <ctype.h>
#include <stdio.h>

int getwords();

int main(void)
{
	char *words[10];
	int nwords;

	char line[] = "deposit 1000 check 10 check 12.34 deposit 50 check 20";
	int i;

	nwords = getwords(line, words, 10);
	for(i = 0; i < nwords; i++)
		printf("%s\n", words[i]);
}



int getwords(char *line, char *words[], int maxwords)
{
char *p = line;
int nwords = 0;

while(1)
	{
	while(isspace(*p))
		p++;

	if(*p == '\0')
		return nwords;

	words[nwords++] = p;

	while(!isspace(*p) && *p != '\0')
		p++;

	if(*p == '\0')
		return nwords;

	*p++ = '\0';

	if(nwords >= maxwords)
		return nwords;
	}
}