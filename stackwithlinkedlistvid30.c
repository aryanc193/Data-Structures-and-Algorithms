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

int main()
{
    struct stack *top = NULL;

    // printf("Before pushing, Full: %d\n", isFull(top));
    // printf("Before pushing, Empty: %d\n", isEmpty(top));
    top = push(top, 1);
    top = push(top, 23);
    top = push(top, 99);
    top = push(top, 75);
    top = push(top, 3);
    top = push(top, 64);
    top = push(top, 57);
    top = push(top, 46);
    top = push(top, 89);
    top = push(top, 6); // ---> Pushed 10 values
    // push(sp, 46); // Stack Overflow since the size of the stack is 10
    // printf("After pushing, Full: %d\n", isFull(top));
    // printf("After pushing, Empty: %d\n", isEmpty(top));
    stackTraversal(top);

    int element = pop(&top);
    printf("Popped element is %d\n", element);
    stackTraversal(top);
    return 0;
}