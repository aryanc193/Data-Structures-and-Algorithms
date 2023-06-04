/* A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data
sorted in ascending/ Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Binary Search Tree for implementation.  */

#include <iostream>
#include <string>

struct node
{
    std::string keyword, meaning;
    node *left, *right;
};

std::string convert(std::string str)
{
    int j, k, len = str.size();
    std::string str_small = str;
    for (j = 0; j < len; j++)
    {
        if (((int)str[j] >= 97 && (int)str[j] <= 122) || ((int)str[j] >= 65 && (int)str[j] <= 90))
        {
            str_small[j] = (int)str[j] <= 90 ? (char)((int)str[j] + 32) : str[j];
        }
        else
            str_small[j] = str[j];
    }
    str_small[j] = '\0';
    return str_small;
}

class dictionary
{
    node *root;

public:
    dictionary()
    {
        root = NULL;
    }
    void create();
    node *insert(node *t, std::string key, std::string value);
    void display(node *t);
    void display();
    void update(std::string key, std::string value);
    void remove(std::string key);
};

void dictionary::create()
{
    int noOfElements;
    std::string keyword, meaning;
    std::cout << "How many elements to be inserted for initializing the binary search tree: ";
    std::cin >> noOfElements;
    std::cout << "\nEnter the keyword in the first element (ROOT): ";
    std::getline(std::cin >> std::ws, keyword);
    std::cout << "Enter the meaning: ";
    std::getline(std::cin >> std::ws, meaning);
    root = insert(root, keyword, meaning);
    for (int i = 1; i < noOfElements; i++)
    {
        std::cout << "\nEnter keyword of (" << i + 1 << ")th element: ";
        std::getline(std::cin >> std::ws, keyword);
        std::cout << "Enter the meaning: ";
        std::getline(std::cin >> std::ws, meaning);
        root = insert(root, keyword, meaning);
    }
}

node *dictionary::insert(node *t, std::string key, std::string value)
{
    std::string key_small = convert(key);
    std::string tKey_small = t == NULL ? "" : convert(t->keyword);
    if (t == NULL)
    {
        node *p = new node;
        p->keyword = key;
        p->meaning = value;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else if (tKey_small > key_small)
    {
        t->left = insert(t->left, key, value);
    }
    else
    {
        t->right = insert(t->right, key, value);
    }
    return t;
}

void dictionary::display(node *t)
{
    if (t != NULL)
    {
        display(t->left);
        std::cout << t->keyword << " - " << t->meaning << std::endl;
        display(t->right);
    }
}

void dictionary::display()
{
    display(root);
}

void dictionary::update(std::string key, std::string value)
{
    node *temp = root;
    while (temp != NULL)
    {
        std::string key_small = convert(key);
        std::string tKey_small = (temp == NULL) ? "" : convert(temp->keyword);
        if (key_small == tKey_small)
        {
            temp->meaning = value;
            std::cout << "Meaning of \"" << temp->keyword << "\" updated!" << std::endl;
            return;
        }
        else if (key_small > tKey_small)
            temp = temp->right;
        else
            temp = temp->left;
    }
    std::cout << "Word not found in the dictionary" << std::endl;
}

void dictionary::remove(std::string key)
{
    node *temp = root, *temp2;
    int LRflag;
    while (temp != NULL)
    {
        std::string key_small = convert(key);
        std::string tkey_small = (temp == NULL) ? "" : convert(temp->keyword);
        if (key_small > tkey_small)
        {
            temp2 = temp;
            temp = temp->right;
            LRflag = 1;
        }
        else if (key_small < tkey_small)
        {
            temp2 = temp;
            temp = temp->left;
            LRflag = 0;
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (LRflag = 0)
                {
                    temp2->left = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp2->right = NULL;
                    delete temp;
                    return;
                }
            }
            else if (temp->left == NULL)
            {
                if (LRflag = 0)
                {
                    temp2->left = temp->right;
                    temp->right = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp2->right = temp->right;
                    temp->right = NULL;
                    delete temp;
                    return;
                }
            }
            else if (temp->left == NULL)
            {
                if (LRflag = 0)
                {
                    temp2->left = temp->left;
                    temp->left = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp2->right = temp->left;
                    temp->left = NULL;
                    delete temp;
                    return;
                }
            }
            else
            {
                temp2 = temp;
                node *temp3 = temp->right;
                while (temp3->left != NULL)
                {
                    temp2 = temp3;
                    temp3 = temp3->left;
                }
                if (temp2 != temp)
                {
                    temp2->left = temp3->right;
                }
                else
                {
                    temp2->right = temp3->left;
                }
                temp->keyword = temp3->keyword;
                temp->meaning = temp3->meaning;
                delete temp3;
                return;
            }
        }
    }
    std::cout << "Word not found in the dictionary, remove operation failed." << std::endl;
}

int main()
{
    dictionary D;
    D.create();
    D.display();
    std::string k, m;
    std::cout << "Enter keyword to update: " << std::endl;
    std::getline(std::cin >> std::ws, k);
    std::cout << "Enter new meaning" << std::endl;
    std::getline(std::cin >> std::ws, m);
    D.update(k, m);
    D.display();
    std::string k2;
    std::cout << "Which key to delete: ";
    std::getline(std::cin >> std::ws, k2);
    D.remove(k2);
    D.display();
    return 0;
}