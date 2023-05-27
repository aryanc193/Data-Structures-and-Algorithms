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

void BST::create()
{
int noOfElements, data;
    std::cout << "How many elements to be inserted for initialization of the BST: " << std::endl;
    std::cin >> noOfElements;
    std::cout << "\nEnter the first element (ROOT): " << std::endl;
    std::cin >> data;
    root = insert(root, data);
    for (int i = 0; i < noOfElements; i++)
    {
        std::cout << "Enter (" << i + 1 << ")th element: " << std::endl;
        std::cin >> data;
        root = insert(root, data);
    }
}

node *insert(node *t, int d)
{
   
}    

int main()
{
    
    return 0;
}
