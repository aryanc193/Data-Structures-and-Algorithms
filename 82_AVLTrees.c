#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createNode(int key)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct node *insert(struct node *p, int key)
{
    if (p == NULL)
    {
        return (createNode(key));
    }

    if (key < p->data)
    {
        p->left = insert(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = insert(p->right, key);
    }

    p->height = 1 + max(getHeight(p->left), getHeight(p->right));
    int bf = getBalanceFactor(p);

    // Left left case
    if (bf > 1 && key < p->left->data)
    {
        return rightRotate(p);
    }

    // Right right case
    if (bf < -1 && key > p->right->data)
    {
        return leftRotate(p);
    }

    // Left right case
    if (bf > 1 && key > p->left->data)
    {
        p->left = leftRotate(p->left);
        return rightRotate(p);
    }

    // Right left case
    if (bf < -1 && key < p->right->data)
    {
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }

    return p;
}

void preOrder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d  ", p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}
