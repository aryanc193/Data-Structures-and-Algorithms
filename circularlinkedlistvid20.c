#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    do
    {
        printf("Data is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 18;
    fourth->next = head;

    linkedListTraversal(head);
    printf("\nCircular linked list after inserting at first position: \n");
    head = insertAtFirst(head, 78);
    linkedListTraversal(head);
    return 0;
}