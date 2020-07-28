#include <stdio.h>
#include <stdlib.h>

void print_list();
void pushEnd();
void push();
int pop();
int remove_last();

typedef struct node {
    int val;
    struct node * next;
} node_t;

int main(void)
{
    /*
    node_t * head2 = NULL;
    head2 = (node_t *) malloc(sizeof(node_t));
    if (head2 == NULL) {
        return 1;
    }

    head2->val = 1;
    head2->next = NULL;
    */


    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = (node_t *) malloc(sizeof(node_t));
    head->next->next->val = 3;
    head->next->next->next = NULL;


    print_list(head);
    pushEnd(head, 4);
    printf("-------\n");
    print_list(head);
    //push(*head, 7);
    printf("-------\n");
    //print_list(head);
    //pop(node_t*head);
    remove_last(head);
    print_list(head);
    // printf("%p\n", node_t.val);

}

void print_list(node_t * head)
{
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void pushEnd(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void push(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;

}

