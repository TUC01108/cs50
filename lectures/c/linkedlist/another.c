// C program to create nodes in a linked list and traverse them (printing to the console the linked list)

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next; //next is a pointer variable of node datatype
} node;


void printList(struct node *tmp)
{
    while (tmp != NULL)
    {
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
}
int main(void)
{
    //creating three nodes
    node *head = NULL;
    node *first = NULL;
    node *second = NULL;

    //allocate enough memory in the heap
    head = (malloc(sizeof(node)));
    first = (malloc(sizeof(node)));
    second = (malloc(sizeof(node)));

    //assigning data to the first node and linking it with the second
    head->data = 8;
    head->next = first;

    //assigning data to the second node and linking it with the third
    first->data = 18;
    first->next = second;

    //assigning data to the third node and making it as the last node
    second->data = 4;
    second->next = NULL;
    node *tmp = head;
    //print the contents of the linked list from the start to the end
    printList(tmp);
    printf("\n");

    return 0;
}