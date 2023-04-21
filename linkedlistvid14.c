#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second;
    struct Node *third;
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth;
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 18;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
}