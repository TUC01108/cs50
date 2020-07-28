#include <stdio.h>		/* for fprintf, stderr */
#include <stdlib.h>		/* for malloc */
#include <string.h>		/* for strlen, strcpy */

struct listnode
	{
	char *item;
	struct listnode *next;
	};
struct listnode node2 = {"world", NULL};
struct listnode node1 = {"hello", &node2};
struct listnode *head = &node1;

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

int main(void)
{
    struct listnode *head = NULL;
	head = prepend("world", head);
	head = prepend("hello", head);

	struct listnode *lp;
	for(lp = head; lp != NULL; lp = lp->next)
		printf("%s\n", lp->item);



}