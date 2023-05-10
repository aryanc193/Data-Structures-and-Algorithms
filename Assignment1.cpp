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
        hashtable = new teleRecord[size];
        flag = new bool[size];
        for (int i = 0; i < size; i++)
        {
            flag[i] = 0;
            hashtable[i].teleNumber = -1;
        }
    }
    void insertLinearProbing(string, long);
    void insertQuadraticProbing(string, long);
    int searchLinearProbing(string);
    int searchQuadraticProbing(string);
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
        ASCII_sum = ASCII_sum + int(t->name[i]);
    }
    loc = (ASCII_sum / t->name.size()) % size;
    for (int i = 0; i < size; i++)
    {
        if (flag[loc] == 0)
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

void Hash::insertQuadraticProbing(string name, long teleNum)
{
    teleRecord *t = new teleRecord;
    t->name = name;
    t->teleNumber = teleNum;
    int loc, ASCII_sum = 0;
    for (int i = 0; i < t->name.size(); i++)
    {
        ASCII_sum = ASCII_sum + int(t->name[i]);
    }
    loc = (ASCII_sum / t->name.size()) % size;
    for (int i = 0; i < size; i++)
    {
        if (flag[loc] == 0)
        {
            hashtable[loc] = *t;
            flag[loc] = 1;
            break;
        }
        else
        {
            loc = (loc + i * i) % size;
        }
    }
}

int Hash::searchLinearProbing(string name)
{
    int loc, ASCII_sum = 0, count = 0;
    for (int i = 0; i < name.size(); i++)
    {
        ASCII_sum = ASCII_sum + int(name[i]);
    }
    loc = (ASCII_sum / name.size()) % size;

    if (flag[loc] == 0)
    {
        cout << name << " does not exist in phonebook." << endl;
        return -1;
    }

    else
    {
        if (hashtable[loc].name == name)
        {
            cout << name << "'s phone number is: " << hashtable[loc].teleNumber << endl;
            return count;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                loc = (loc + 1) % size;
                count++;
                if (hashtable[loc].name == name)
                {
                    cout << name << "'s phone number is: " << hashtable[loc].teleNumber << endl;
                    return count;
                }
            }
        }
    }
}

int Hash::searchQuadraticProbing(string name)
{
    int loc, ASCII_sum = 0, count = 0;
    for (int i = 0; i < name.size(); i++)
    {
        ASCII_sum = ASCII_sum + int(name[i]);
    }
    loc = (ASCII_sum / name.size()) % size;

    if (flag[loc] == 0)
    {
        cout << name << " does not exist in phonebook." << endl;
        return -1;
    }

    else
    {
        if (hashtable[loc].name == name)
        {
            cout << name << "'s phone number is: " << hashtable[loc].teleNumber << endl;
            return count;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                loc = (loc + i * i) % size;
                count++;
                if (hashtable[loc].name == name)
                {
                    cout << name << "'s phone number is: " << hashtable[loc].teleNumber << endl;
                    return count;
                }
            }
        }
    }
}

void Hash::display()
{
    teleRecord *t;
    for (int i = 0; i < size; i++)
    {
        t = &hashtable[i];
        cout << t->name << " - " << t->teleNumber << endl;
    }
}

int main()
{
    int ch, n1, n2, s;
    // char ans;
    string na;
    long num;
    cout << "Enter the size of the telephone book: ";
    cin >> s;
    Hash b1(s), b2(s);

    do
    {
        cout << "\nEnter the task you want to perform:\n1. Insert entry into the book\n2. Search entry from the book\n3. Display the book\n4. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the name: ";
            getline(cin >> ws, na);
            cout << "\nEnter telephone number: ";
            cin >> num;
            b1.insertLinearProbing(na, num);
            b2.insertQuadraticProbing(na, num);
            break;

        case 2:
            cout << "\nEnter the name you want to search: ";
            getline(cin >> ws, na);
            n1 = b1.searchLinearProbing(na);
            n2 = b2.searchQuadraticProbing(na);
            cout << "Number of comparisons in linear probing: " << n1 << endl;
            cout << "Number of comparisons in quadratic probing: " << n2 << endl;
            break;

        case 3:
            cout << "\n----------------TELEPHONE BOOK----------------" << endl;
            cout << "\nLinear probing" << endl;
            b1.display();
            cout << "\nQuadratic Probing" << endl;
            b2.display();
            break;
       
        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (ch!=4);

    return 0;
}
