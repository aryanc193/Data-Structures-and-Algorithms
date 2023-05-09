/* Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers */

#include <iostream>
#include <string>
using namespace std;

struct teleRecord
{
    long teleNumber;
    string name;
};

class Hash
{
private:
    int size;
    bool *flag;
    teleRecord *hashtable;

public:
    Hash()
    {
        size = 10;
        cout << "Creating telephone book of size " << size << endl;
        hashtable = new teleRecord[size];
        flag = new bool[size];
        for (int i = 0; i < size; i++)
        {
            flag[i] = 0;
            hashtable[i].teleNumber = -1;
        }
    }

    Hash(int a)
    {
        size = a;
        cout << "Creating telephone book of size " << a << endl;
        hashtable = new teleRecord[a];
        flag = new bool[a];
        for (int i = 0; i < a; i++)
        {
            flag[i] = 0;
            hashtable[i].teleNumber = -1;
        }
    }
    void insertLinearProbing(string, long);
    void insertQuadratricProbing(string, long);
    void searchLinearProbing(string, long);
    void searchQuadraticProbing(string, long);
    void display();
};

void Hash::insertLinearProbing(string name, long teleNum)
{
    teleRecord *t = new teleRecord;
    t->name = name;
    t->teleNumber = teleNum;
    int loc, ASCII_sum = 0;
    for (int i = 0; i < t->name.size(); i++)
    {
        ASCII_sum = ASCII_sum + int(t->name.size());
    }
    loc = (ASCII_sum / t->name.size()) % size;
    for (int i = 0; i < size; i++)
    {
        if (flag[loc] = 0)
        {
            hashtable[loc] = *t;
            flag[loc] = 1;
            break;
        }
        else
        {
            loc = (loc + 1) % size;
        }
    }
}

void Hash::insertQuadratricProbing(string name, long teleNum)
{
    teleRecord *t = new teleRecord;
    t->name = name;
    t->teleNumber = teleNum;
    int loc, ASCII_sum = 0;
    for (int i = 0; i < t->name.size(); i++)
    {
        ASCII_sum = ASCII_sum + int(t->name.size());
    }
    loc = (ASCII_sum / t->name.size()) % size;
    for (int i = 0; i < size; i++)
    {
        if (flag[loc] = 0)
        {
            hashtable[loc] = *t;
            flag[loc] = 1;
            break;
        }
        else
        {
            loc = (loc + i*i) % size;
        }
    }
}

void Hash::searchLinearProbing(string name, long teleNum)
{
}

void Hash::searchQuadraticProbing(string name, long teleNum)
{
}

int main()
{

    return 0;
}
