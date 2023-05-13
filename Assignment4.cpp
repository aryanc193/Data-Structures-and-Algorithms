/* To create ADT that implement the "set" concept.
a. Add (newElement) -Place a value into the set
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection
e. Intersection of two sets
f. Union of two sets
g. Difference between two sets
h.Subset */

#include <iostream>
using namespace std;

class Set
{
    int *arr, capacity, top;

public:
    Set()
    {
        capacity = 10;
        arr = new int[capacity];
        top = -1;
        cout << "Set of default capacity 10 created." << endl;
    }

    Set(int n)
    {
        capacity = n;
        arr = new int[capacity];
        top = -1;
        cout << "Set of capacity " << n + 1 << " created." << endl;
    }
    void add(int newElement);
    void remove(int element);
    bool contains(int element);
    int size();
    Set *intersection(Set *B);
    Set *uni(Set *B);
    Set *diff(Set *B);
    bool subset(Set *B);
    void display();
};

void Set::add(int newElement)
{
    if (top >= capacity)
    {
        cout << "Set Overflow cannot add elements" << endl;
    }
    else if (this->contains(newElement))
    {
        cout << "Set already contains this element." << endl;
    }
    else
    {
        top++;
        arr[top] = newElement;
        cout << "Element " << newElement << " was added to the set." << endl;
    }
}

void Set::remove(int element)
{
    if (top < 0)
    {
        cout << "Set is empty, cannot delete anymore elements." << endl;
    }
    else
    {
        for (int i = 0; i < this->arr[top] + 1; i++)
        {
            if (this->arr[i] == element)
            {
                this->arr[i] = this->top;
                top--;
                cout << "The element " << element << " was removed from the set." << endl;
                return;
            }
        }
        cout << "Element not found." << endl;
    }
}

bool Set::contains(int element)
{
    if (this->arr[top] < 0)
    {
        return 0;
    }

    for (int i = 0; i < size(); i++)
    {
        if (this->arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

int Set::size()
{
    return this->arr[top] + 1;
}

Set *Set::intersection(Set *B)
{
    Set *C = new Set(this->arr[capacity] + B->arr[capacity]);
    for (int i = 0; i < this->size(); i++)
    {
        for (int j = 0; j < B->size(); j++)
        {
            if (this->arr[i] == B->arr[j])
            {
                C->add(B->arr[j]);
            }
        }
    }
    return C;
}

Set *Set::uni(Set *B)
{
    Set *C = new Set(this->arr[capacity] + B->arr[capacity]);
    for (int i = 0; i < this->size(); i++)
    {
        C->add(this->arr[i]);
    }

    for (int i = 0; i < B->size(); i++)
    {
        for (int j = 0; j < this->size() - 1; j++)
        {
            if (B->arr[i] != this->arr[j])
            {
                C->add(B->arr[i]);
            }
        }
    }
    return C;
}

Set *Set::diff(Set *B)
{
    Set *C = new Set(this->arr[capacity] + B->arr[capacity]);
    for (int i = 0; i < this->size(); i++)
    {
        for (int j = 0; j < B->size(); j++)
        {
            if (this->arr[i] != B->arr[j])
            {
                C->add(this->arr[i]);
            }
        }
    }
    return C;
}

bool Set::subset(Set *B)
{
    for (int i = 0; i < B->size(); i++)
    {
        for (int j = 0; j < this->size(); j++)
        {
            if (!B->contains(this->arr[j]))
                return 0;
        }
    }
    return true;
}

void Set::display()
{
    cout << "{ ";
    for (int i = 0; i < this->top; i++)
    {
        cout << this->arr[i] << ",";
    }
    cout << this->arr[top] << "}" << endl;
}

int main()
{
    int sizeA, sizeB;
    cout << "Enter the size you want to allot to set A and B:\n"
         << endl;
    cin >> sizeA >> sizeB;
    Set A(sizeA - 1), B(sizeB - 1), *C;
    int ch, ch2, x;
    char ans, setName;
    do
    {
        cout << "Which operation do you want to perform on sets?\n1. Add element\n2. Remove element\n3. Check if a set contains an element\n4. Size of set\n5. Display a set\n6. Intersection of the 2 sets\n7. Union of the 2 sets\n8. Difference of 2 sets\n9. Check if a set is subset of another\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element you want to add: " << endl;
            cin >> x;
            cout << "Which set do you want to add it to? A or B: " << endl;
            cin >> setName;
            if (setName == 'A')
            {
                A.add(x);
                cout << "Element added to set A." << endl;
            }
            if (setName == 'B')
            {
                B.add(x);
                cout << "Element added to set B." << endl;
            }
            break;

        case 2:
            cout << "Enter element you want to remove: " << endl;
            cin >> x;
            cout << "Which set do you want to remove it from? A or B: " << endl;
            cin >> setName;
            if (setName == 'A')
            {
                A.remove(x);
                cout << "Element " << x << " removed from set A." << endl;
            }
            if (setName == 'B')
            {
                B.remove(x);
                cout << "Element " << x << " removed from set B." << endl;
            }
            break;

        case 3:
            cout << "Enter element you want to check: " << endl;
            cin >> x;
            cout << "Which set do you want to check in? A or B: " << endl;
            cin >> setName;
            if (setName == 'A')
            {
                if (A.contains(x))
                {
                    cout << "Element " << x << " is in set A." << endl;
                }
                else
                {
                    cout << "Element " << x << " is not in set A." << endl;
                }
            }
            if (setName == 'B')
            {
                if (B.contains(x))
                {
                    cout << "Element " << x << " is in set B." << endl;
                }
                else
                {
                    cout << "Element " << x << " is not in set B." << endl;
                }
            }
            break;

        case 4:
            cout << "Which set do you want the size of? A or B: " << endl;
            cin >> setName;
            if (setName == 'A')
            {
                cout << "Set A has size " << A.size() << endl;
            }
            if (setName == 'B')
            {
                cout << "Set B has size " << B.size() << endl;
            }
            break;

        case 5:
            cout << "Which set do you want to see? A or B: " << endl;
            cin >> setName;
            if (setName == 'A')
            {
                cout << "Set A : ";
                A.display();
                cout << endl;
            }
            if (setName == 'B')
            {
                cout << "Set B : ";
                B.display();
                cout << endl;
            }
            break;

        case 6:
            cout << "Intersection of  A & B is: ";
            C = A.intersection(&B);
            cout << endl;
            break;

        case 7:
            cout << "Union of  A & B is: ";
            C = A.uni(&B);
            C->display();
            cout << endl;
            break;

        case 8:
            cout << "1. A-B\n2. B-A?\nEnter which one do you want to see: ";
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                cout << "Difference of  A & B is: ";
                C = A.diff(&B);
                C->display();
                cout << endl;
                break;
            case 2:
                cout << "Difference of  B & A is: ";
                C = B.diff(&A);
                C->display();
                cout << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
            }
            break;

        case 9:
            cout << "1. A subset of B\n2. B is subset of A\nEnter which one do you want to see: ";
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                if (A.subset(&B))
                {
                    cout << "A is a subset of B." << endl;
                }
                else
                {
                    cout << "A is not a subset of B." << endl;
                }
                break;
            case 2:
                if (B.subset(&A))
                {
                    cout << "B is a subset of A." << endl;
                }
                else
                {
                    cout << "B is not a subset of A." << endl;
                }
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
            }
            break;

        default:
            break;
        }
        cout << "Do you want to continue or exit?\nPress any key to continue\nPress N to exit" << endl;
        cin >> ans;
    } while (ans != 'N' || ans != 'n');

    return 0;
}
