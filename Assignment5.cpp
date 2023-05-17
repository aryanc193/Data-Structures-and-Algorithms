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



int main()
{
    
    return 0;
}
