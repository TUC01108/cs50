// Stack example

#include <stdio.h>		/* for fprintf, stderr */
#include <stdlib.h>		/* for malloc */

struct listnode
	{
	char *item;
	struct listnode *next;
	};
struct listnode node2 = {"world", NULL};
struct listnode node1 = {"hello", &node2};
struct listnode *head = &node1;

int main(void)
{
    char *newword = "test";
	struct listnode *newnode = malloc(sizeof(struct listnode));
	if(newnode == NULL)
		{
		fprintf(stderr, "out of memory\n");
		exit(1);
		}

	newnode->item = newword;
	newnode->next = head;
	head = newnode;

	struct listnode *lp;
	for(lp = head; lp != NULL; lp = lp->next)
		printf("%s\n", lp->item);



}