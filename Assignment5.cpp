/* A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method. */

#include <iostream>
#define MAX 15

struct node
{
    std::string part;
    node *left, *right;
};

class stack
{
    node *arr[MAX];
    bool flag[MAX];
    int top;

    public:
    stack()
    {
        top = -1;
    }
    bool empty();
    void push(node *p);
    void push(node *p, bool f);
    bool flagValue();
    node *pop();
};
bool stack::empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void stack::push(node *p)
{
    if (top == MAX - 1)
    {
        return;
    }
    top++;
    arr[top] = p;
}
void stack::push(node *p, bool f)
{
    if (top == MAX - 1)
    {
        return;
    }
    top++;
    arr[top] = p;
    flag[top] = f;
}
bool stack::flagValue()
{
    return flag[top];
}
node *stack::pop()
{
    node *temp;
    temp = arr[top];
    top--;
    return temp;
}

class queue
{
    node *arr[MAX];
    int f, r;

public:
    queue()
    {
        f = r = -1;
    }
    bool empty();
    void insert(node *p);
    node *remove();
};
bool queue::empty()
{
    if (f == -1 && r == -1)
    {
        return 1;
    }
    return 0;
}
void queue::insert(node *p)
{
    if (this->empty())
    {
        r = f = 0;
    }
    else
    {
        r++;
    }
    arr[r] = p;
}
node *queue::remove()
{
    node *t = arr[f];
    if (r == f)
    {
        r = f = -1;
    }
    else
    {
        f++;
    }
    return t;
}

class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }
    node *create();
    void recInOrder(node *t);
    void recPreOrder(node *t);
    void recPostOrder(node *t);
    void nonrecInOrder(node *t);
    void nonrecPreOrder(node *t);
    void nonrecPostOrder(node *t);
    void BFS(node *t);
    void menu();
};
node *tree::create()
{
    std::string c;
    node *temp = new node;
    std::cout << "Enter the part of the book (NULL to exit): " << std::endl;
    std::getline(std::cin >> std::ws, c);
    if (c != "NULL")
    {
        temp->part = c;
        std::cout << "Enter left child of " << c << std::endl;
        temp->left = create();
        std::cout << "Enter right child of " << c << std::endl;
        temp->right = create();
    }
    else
    {
        temp = NULL;
    }
    return temp;
}
void tree::recInOrder(node *t)
{
    if (t != NULL)
    {
        recInOrder(t->left);
        std::cout << t->part << "  ";
        recInOrder(t->right);
    }
}
void tree::recPreOrder(node *t)
{
    if (t != NULL)
    {
        std::cout << t->part << "  ";
        recPreOrder(t->left);
        recPreOrder(t->right);
    }
}
void tree::recPostOrder(node *t)
{
    if (t != NULL)
    {
        recPostOrder(t->left);
        recPostOrder(t->right);
        std::cout << t->part << "  ";
    }
}

void tree::nonrecInOrder(node *t)
{
    stack s;
    node *temp;
    temp = t;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->left;
    }
    while (!s.empty())
    {
        temp = s.pop();
        std::cout << temp->part << "  ";
        temp = temp->right;
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}
void tree::nonrecPreOrder(node *t)
{
    stack s;
    node *temp;
    temp = t;
    while (temp != NULL)
    {
        std::cout << temp->part << "  ";
        s.push(temp);
        temp = temp->left;
    }
    while (!s.empty())
    {
        temp = s.pop();
        temp = temp->right;
        while (temp != NULL)
        {
            std::cout << temp->part << "  ";
            s.push(temp);
            temp = temp->left;
        }
    }
}
void tree::nonrecPostOrder(node *t)
{
    stack s;
    node *temp;
    bool flag;
    temp = t;
    while (temp != NULL)
    {
        s.push(temp, false);
        temp = temp->left;
    }
    while (!s.empty())
    {
        flag = s.flagValue();
        temp = s.pop();
        if (flag == false)
        {
            s.push(temp, true);
            temp = temp->right;
            while (temp != NULL)
            {
                s.push(temp, false);
                temp = temp->left;
            }
        }
        else
        {
            std::cout << temp->part << "  ";
        }
    }
}

void tree::BFS(node *t)
{
    queue *q1 = new queue;
    queue *q2 = new queue;
    q1->insert(t);
    std::cout << t->part;
    while (!q1->empty())
    {
        q2 = new queue;
        std::cout << std::endl;
        while (!q1->empty())
        {
            node *t = q1->remove();
            if (t->left != NULL)
            {
                std::cout << t->left->part << "  ";
                q2->insert(t->left);
            }
            if (t->right != NULL)
            {
                std::cout << t->right->part << "  ";
                q2->insert(t->right);
            }
        }
        q1 = q2;
    }
}

void tree::menu()
{
    std::cout << "Creating new binary tree:\n"
              << std::endl;
    root = this->create();
    std::cout << std::endl;
    std::cout << "\nRECURSIVE: " << std::endl;
    std::cout << "Inorder: " << std::endl;
    recInOrder(root);
    std::cout << "\nPreorder: " << std::endl;
    recPreOrder(root);
    std::cout << "\nPostorder: " << std::endl;
    recPostOrder(root);
    std::cout << "\n\nNON RECURSIVE: " << std::endl;
    std::cout << "Inorder: " << std::endl;
    nonrecInOrder(root);
    std::cout << "\nPreorder: " << std::endl;
    nonrecPreOrder(root);
    std::cout << "\nPostorder: " << std::endl;
    nonrecPostOrder(root);
    std::cout << "\n\nBreadth First Traversal: " << std::endl;
    BFS(root);
    std::cout << std::endl;
}

int main()
{
    tree book;
    book.menu();   
    return 0;
}
