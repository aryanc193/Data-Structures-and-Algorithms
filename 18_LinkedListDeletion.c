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
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *delAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

struct Node *delAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct Node *delAtTheEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

struct Node *delNodeData(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
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
    struct Node *fifth;
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 18;
    fourth->next = fifth;

    fifth->data = 77;
    fifth->next = NULL;

    linkedListTraversal(head);
    // printf("\nAfter deletion at first node: \n");
    // head = delAtFirst(head);
    // linkedListTraversal(head);

    // printf("\nAfter deletion at index: \n");
    // delAtIndex(head, 3);
    // linkedListTraversal(head);

    // printf("\nAfter deletion at end: \n");
    // delAtTheEnd(head);
    // linkedListTraversal(head);

    printf("\nAfter deletion of a particular data: \n");
    delNodeData(head, 12);
    linkedListTraversal(head);
    return 0;
}
