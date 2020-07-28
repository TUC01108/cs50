#include <stdio.h>		/* for fprintf, stderr */
#include <stdlib.h>		/* for malloc */
#include <string.h>		/* for strlen, strcpy */

struct listnode
	{
	char *item;
	struct listnode *next;
	};

struct listnode *prepend(char *newword, struct listnode *oldhead)
{
struct listnode *newnode = malloc(sizeof(struct listnode));
if(newnode == NULL)
	{
	fprintf(stderr, "out of memory\n");
	exit(1);
	}

newnode->item = malloc(strlen(newword) + 1);
if(newnode->item == NULL)
	{
	fprintf(stderr, "out of memory\n");
	exit(1);
	}
strcpy(newnode->item, newword);

newnode->next = oldhead;
return newnode;
}
#define MAXLINE 200

char line[MAXLINE];
struct listnode *head = NULL;
struct listnode *lp;


int main(void)
{

	while(getline(line, MAXLINE) != EOF)
		head = prepend(line, head);

	for(lp = head; lp != NULL; lp = lp->next)
		printf("%s\n", lp->item);
}