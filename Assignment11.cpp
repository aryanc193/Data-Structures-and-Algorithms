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
    for (int j = 0; j < len; j++)
    {
        if (((int)str[j] >= 97 && (int)str[j] <= 122) || ((int)str[j] >= 65 && (int)str[j] <= 90))
        {
            str_small[j] = (int)str[j] <= 90 ? (char)((int)str[j] + 32) : str[j];
        }
        else
        {
            str_small[j] = str[j];
        }
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
    
}

int main()
{

    return 0;
}
