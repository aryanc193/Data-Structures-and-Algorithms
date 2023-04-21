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

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
 
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtTheEnd(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
       p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return ptr;
};

struct Node * insertAfterNode(struct Node *first, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = first->next;
    first->next = ptr;
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

    second->data = 11;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 18;
    fourth->next = NULL;

    linkedListTraversal(head);
    printf("\nAfter Insertion at first node: \n");
    head = insertAtFirst(head, 56);
    linkedListTraversal(head);

    printf("\nAfter Insertion at index: \n");
    insertAtIndex(head, 68, 4);
    linkedListTraversal(head);

    printf("\nAfter Insertion at end: \n");
    insertAtTheEnd(head, 144);
    linkedListTraversal(head);

    printf("\nAfter Insertion after a particular node: \n");
    insertAfterNode(second, 77);
    linkedListTraversal(head);
    return 0;
}