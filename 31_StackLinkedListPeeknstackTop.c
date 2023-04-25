#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

int isEmpty(struct stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *top)
{
    struct stack *p = (struct stack *)malloc(sizeof(struct stack));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct stack *push(struct stack *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", x);
    }
    else
    {
        struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
        ptr->next = top;
        ptr->data = x;
        top = ptr;
        return top;
    }
}

int pop(struct stack **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct stack *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

void stackTraversal(struct stack *top)
{
    while (top != NULL)
    {
        printf("Data: %d\n", top->data);
        top = top->next;
    }
}

int peek(struct stack *top, int pos)
{
    struct stack *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop(struct stack *top){
    return top->data;
}

int main()
{
    struct stack *top = NULL;

    top = push(top, 1);
    top = push(top, 23);
    top = push(top, 99);
    top = push(top, 75);
    top = push(top, 3);
    stackTraversal(top);

    int element = pop(&top);
    printf("Popped element is %d\n", element);
    stackTraversal(top);

    printf("value at position 3 is: %d\n", peek(top, 3));
    printf("value at top is: %d\n", stackTop(top));
    return 0;
}
