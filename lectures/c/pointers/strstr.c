#include <stddef.h>
#include <stdio.h>

char *mystrstr(char input[], char pat[]);

int main (void)
{
    if(mystrstr("Yordana", "dana") == NULL)
		printf("no\n");
	else	printf("yes\n");
}


char *mystrstr(char input[], char pat[])
{
	char *start, *p1, *p2;
	for(start = &input[0]; *start != '\0'; start++)
		{		/* for each position in input string... */
		p1 = pat;	/* prepare to check for pattern string there */
		p2 = start;
		while(*p1 != '\0')
			{
			if(*p1 != *p2)	/* characters differ */
				break;
			p1++;
			p2++;
			}
		if(*p1 == '\0')		/* found match */
			return start;
		}

	return NULL;
}