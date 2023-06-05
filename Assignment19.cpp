/* A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/descending order. Also find how many maximum comparisons may require for finding any keyword. Use Height balance tree and find the complexity for finding a keyword */
#include <iostream>
#include <string>

class node
{
public:
    std::string m, k;
    class node *left, *right;
};

class dict
{
public:
    node *root;
    void create();
    void disp(node *);
    void insert(node *, node *);
    int search(node *, std::string);
    int update(node *, std::string);
    node *del(node *, std::string);
    node *min(node *);
};

void dict::create()
{
    node *temp;
    int ch;
    do
    {
        temp = new node;
        std::cout << "\nEnter Keyword: ";
        std::cin >> temp->k;
        std::cout << "\nEnter Meaning: ";
        std::cin >> temp->m;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
            insert(root, temp);
        std::cout << "\nDo you want to add more?(y = 1/ n = 0): ";
        std::cin >> ch;
    } while (ch == 1);
}

void dict::insert(node *root, node *temp)
{
    if (temp->k < root->k)
    {
        if (root->left == NULL)
        {
            root->left = temp;
        }
        else
            insert(root->left, temp);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = temp;
        }
        else
            insert(root->left, temp);
    }
}

void dict::disp(node *root)
{
    if (root != NULL)
    {
        disp(root->left);
        std::cout << "\nKey Word: " << root->k;
        std::cout << "\nMeaning: " << root->m;
        disp(root->right);
    }
}

int dict::search(node *root, std::string k)
{
    int c = 0;
    while (root != NULL)
    {
        c++;
        if (k == root->k)
        {
            std::cout << "\nNo of comparisons: " << c;
            return 1;
        }
        if (k < root->k)
        {
            root = root->left;
        }
        if (k > root->k)
        {
            root = root->right;
        }
    }
    return -1;
}

int dict::update(node *root, std::string k)
{
    while (root != NULL)
    {
        if (k == root->k)
        {
            std::cout << "\nEnter new meaning of keyword " << root->k;
            std::cin >> root->m;
            return 1;
        }
        if (k < root->k)
            root = root->left;
        if (k > root->k)
            root = root->right;
    }
    return -1;
}
node *dict::del(node *root, std::string k)
{
    node *temp;
    if (root == NULL)
    {
        std::cout << "\nElement not found.";
        return root;
    }
    if (k < root->k)
    {
        root->left = del(root->left, k);
        return root;
    }
    if (k > root->k)
    {
        root->right = del(root->right, k);
        return root;
    }
    if (root->right == NULL && root->left == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return NULL;
    }
    else if (root->left == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return temp;
    }
    temp = min(root->right);
    root->k = temp->k;
    root->right = del(root->right, temp->k);
    return root;
}

node *dict::min(node *q)
{
    while (q->left != NULL)
    {
        q = q->left;
    }
    return q;
}

int main()
{
    int ch;
    dict d;
    d.root = NULL;
    do
    {

        std::cout << "\nMenu\n1. Create\n2. Display\n3. Search\n4.Update\n5. Delete\nEnter your choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL)
            {
                std::cout << "\nNo keyword present." << std::endl;
            }
            else
                d.disp(d.root);
            break;
        case 3:
            if (d.root == NULL)
            {
                std::cout << "\nDictionary is Empty.First add keywords then try again ";
            }
            else
            {
                std::cout << "\nEnter Keyword which u want to search :";
                std::string k;
                std::getline(std::cin >> std::ws, k);
                if (d.search(d.root, k) == 1)
                    std::cout << "\nKeyword Found";
                else
                    std::cout << "\nKeyword Not Found";
            }
            break;
        case 4:
            if (d.root == NULL)
            {
                std::cout << "\nDictionary is Empty.First add keywords then try again ";
            }
            else
            {
                std::cout << "\nEnter Keyword which meaning want to update :";
                std::string k;
                std::getline(std::cin >> std::ws, k);
                if (d.update(d.root, k) == 1)
                    std::cout << "\nMeaning Updated";
                else
                    std::cout << "\nMeaning Not Found";
            }
            break;
        case 5:
            if (d.root == NULL)
            {
                std::cout << "\nDictionary is Empty.First add keywords then try again ";
            }
            else
            {
                std::cout << "\nEnter Keyword which u want to delete :";
                std::string k;
                std::getline(std::cin >> std::ws, k);
                if (d.root == NULL)
                {
                    std::cout << "\nNo any Keyword";
                }
                else
                {
                    d.root = d.del(d.root, k);
                }
            }

        default:
            break;
        }
    } while (ch <= 5);

    return 0;
}