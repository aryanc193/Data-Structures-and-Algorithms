#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void linkedListTraversalBackwards(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

void linkedListTraversal2(struct Node *head)
{
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    head->prev = ptr;
    ptr->prev = NULL;
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

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
    head->prev = NULL;

    second->data = 11;
    second->next = third;
    second->prev = head;

    third->data = 14;
    third->next = fourth;
    third->prev = second;

    fourth->data = 18;
    fourth->next = NULL;
    fourth->prev = third;

    linkedListTraversal(head);
    linkedListTraversalBackwards(fourth);

    printf("\nAfter Insertion at first node: \n");
    head = insertAtFirst(head, 56);
    linkedListTraversal(head);
    linkedListTraversalBackwards(fourth);

    return 0;
}
