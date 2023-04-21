#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
 
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing an element manually
    s->arr[0] = 7;
    s->top++;
    s->arr[1] = 72;
    s->top++;
    s->arr[2] = 4;
    s->top++;
    s->arr[3] = 5;
    s->top++;
    s->arr[4] = 67;
    s->top++;
    s->arr[5] = 69;
    s->top++;
 
    // Check if stack is empty
    if(isEmpty(s)==1){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
 
    if(isFull(s)==1){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }
    return 0;
}