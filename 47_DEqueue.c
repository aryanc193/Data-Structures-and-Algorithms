#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f, r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueueRear(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("\nThis queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element from rear: %d\n", val);
    }
}

void enqueueFront(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("\nThis queue is full\n");
    }
    else if (q->f == -1)
    {
        printf("Cannot insert from front, front limit reached!\n");
    }
    else
    {
        q->arr[q->f] = val;
        q->f--;
        printf("Enqued element from front: %d\n", val);
    }
}

int dequeueFront(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("\nThis queue is empty cannot delete!\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}

int dequeueRear(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("\nThis queue is empty cannot delete!\n");
    }
    else
    {
        a = q->arr[q->r];
        q->r--;
        return a;
    }
}

int main(){
    struct queue q;
    q.size = 6;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueueRear(&q, 1);
    enqueueRear(&q, 2);
    enqueueRear(&q, 3);
    enqueueRear(&q, 4);
    enqueueRear(&q, 5);
    enqueueRear(&q, 6);
    // enqueueRear(&q, 7);

    printf("Dequeuing element from rear %d\n", dequeueRear(&q));
    printf("Dequeuing element from rear %d\n", dequeueRear(&q));
    printf("Dequeuing element from front %d\n", dequeueFront(&q));
    printf("Dequeuing element from front %d\n", dequeueFront(&q));

    enqueueFront(&q, 11); 
    enqueueFront(&q, 12); 
    // enqueueFront(&q, 13); 
    printf("Dequeuing element from front %d\n", dequeueFront(&q));
    printf("Dequeuing element from rear %d\n", dequeueRear(&q));
    printf("Dequeuing element from front %d\n", dequeueFront(&q));
    printf("Dequeuing element from front %d\n", dequeueFront(&q));
    printf(dequeueRear(&q));
 
    return 0;
}
