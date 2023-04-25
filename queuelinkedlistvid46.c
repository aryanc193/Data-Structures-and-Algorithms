#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full!!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (f == NULL)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        n = f;
        f = f->next;
        val = n->data;
        return val;
        free(n);
    }
}

int main()
{
    printf("Dequeuing element: %d\n", dequeue());
    enqueue(32);
    enqueue(345);
    enqueue(34);
    linkedListTraversal(f);
    printf("Dequeuing element: %d\n", dequeue());

    return 0;
}