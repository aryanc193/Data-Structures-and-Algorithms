/* Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
v. Search a value */

#include <iostream> 

struct node
{
    int data;
    node *left, *right;
};

class BST
{
    node *root;

    public:
    BST()
    {
        root = NULL;
    }
    void create();
    node *insert(node *t, int d);
    void display(node *t);
    int min();
    int max();
    bool search(int d);
    node *swap(node *t);
    int longestPath(node *t);
    friend void menu(BST tree);
};

int main()
{
    
    return 0;
}
