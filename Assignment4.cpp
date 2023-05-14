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

class Set
{
    int *arr, capacity, top;

public:
    Set()
    {
        capacity = 10;
        arr = new int[capacity];
        top = -1;
        std::cout << "Set of default capacity 10 created." << std::endl;
    }

    Set(int n)
    {
        capacity = n;
        arr = new int[capacity];
        top = -1;
        // std::cout << "Set of capacity " << n + 1 << " created." << std::endl;
    }
    void create(int size);
    void add(int newElement);
    void remove(int element);
    bool contains(int element);
    int size();
    Set *intersection(Set B);
    Set *uni(Set B);
    Set *diff(Set B);
    bool subset(Set B);
    void display();
};

void Set::create(int size)
{
    int x;
    std::cout << "Enter Elements" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> x;
        this->add(x);
    }
}

void Set::add(int newElement)
{
    if (top >= capacity)
    {
        std::cout << "Set Overflow cannot add elements" << std::endl;
        return;
    }
    else if (this->contains(newElement))
    {
        // std::cout << "Set already contains this element." << std::endl;
        return;
    }
    else
    {
        top++;
        arr[top] = newElement;
        // std::cout << "Element " << newElement << " was added to the set." << std::endl;
    }
}

void Set::remove(int element)
{
    if (top < 0)
    {
        std::cout << "Set is empty, cannot delete anymore elements." << std::endl;
    }
    else
    {
        for (int i = 0; i < this->arr[top] + 1; i++)
        {
            if (this->arr[i] == element)
            {
                this->arr[i] = this->top;
                top--;
                // std::cout << "The element " << element << " was removed from the set." << std::endl;
                return;
            }
        }
        std::cout << "Element not found." << std::endl;
    }
}

bool Set::contains(int element)
{
    if (top < 0)
    {
        return 0;
    }

    for (int i = 0; i < size(); i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

int Set::size()
{
    return top + 1;
}

Set *Set::intersection(Set B)
{
    Set *C = new Set(this->capacity + B.capacity);
    for (int i = 0; i < this->top + 1; i++)
    {
        for (int j = 0; j < B.top + 1; j++)
        {
            if (this->arr[i] == B.arr[j])
            {
                C->add(B.arr[j]);
            }
        }
    }
    return C;
}

Set *Set::uni(Set B)
{
    Set *C = new Set(this->capacity + B.capacity);
    for (int i = 0; i < this->top + 1; i++)
    {
        C->add(this->arr[i]);
    }
    for (int i = 0; i < B.top + 1; i++)
    {
        for (int j = 0; j < this->top; j++)
        {
            if (B.arr[i] != this->arr[j])
            {
                C->add(B.arr[i]);
            }
        }
    }
    return C;
}

Set *Set::diff(Set B)
{
    Set *C = new Set(this->capacity + B.capacity);
    int flag;
    for (int i = 0; i < this->top + 1; i++)
    {
        for (int j = 0; j < B.top + 1; j++)
        {
            if (this->arr[i] == B.arr[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            C->add(this->arr[i]);
        }
    }
    return C;
}

bool Set::subset(Set B)
{
    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < this->size(); j++)
        {
            if (!B.contains(this->arr[j]))
                return 0;
        }
    }
    return true;
}

void Set::display()
{
    std::cout << "{";
    for (int i = 0; i < this->top; i++)
    {
        std::cout << this->arr[i] << ", ";
    }
    std::cout << this->arr[top] << "}" << std::endl;
}

int main()
{
    int sizeA, sizeB;
    std::cout << "Enter the size you want to allot to set A and B:" << std::endl;
    std::cin >> sizeA >> sizeB;
    Set A(sizeA - 1), B(sizeB - 1), *C;
    int ch, ch2, x;
    char ans, setName;
    // std::cout << "\nCreate set A: " << std::endl;
    // A.create(sizeA);
    // std::cout << "\nCreate set B: " << std::endl;
    // B.create(sizeB);
    do
    {
        std::cout << "\nWhich operation do you want to perform on sets?\n1. Add element\n2. Remove element\n3. Check if a set contains an element\n4. Size of set\n5. Display a set\n6. Intersection of the 2 sets\n7. Union of the 2 sets\n8. Difference of 2 sets\n9. Check if a set is subset of another\n10. Exit\nEnter your choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            std::cout << "Which set do you want to add it to? A or B: " << std::endl;
            std::cin >> setName;
            std::cout << "Enter element you want to add: " << std::endl;
            std::cin >> x;
            if (setName == 'A' || setName == 'a')
            {
                A.add(x);
                std::cout << "Element " << x << " was added to the set A." << std::endl;
            }
            else if (setName == 'B' || setName == 'b')
            {
                B.add(x);
                std::cout << "Element " << x << " was added to the set B." << std::endl;
            }
            else
                std::cout << "Invalid Set!!!";
            break;

        case 2:
            std::cout << "Which set do you want to remove it from? A or B: " << std::endl;
            std::cin >> setName;
            std::cout << "Enter element you want to remove: " << std::endl;
            std::cin >> x;
            if (setName == 'A' || setName == 'a')
            {
                A.remove(x);
                std::cout << "The element " << x << " was removed from the set A." << std::endl;
            }
            else if (setName == 'B' || setName == 'b')
            {
                B.remove(x);
                std::cout << "The element " << x << " was removed from the set B." << std::endl;
            }
            else
                std::cout << "Invalid Set!!!";
            break;

        case 3:
            std::cout << "Which set do you want to check in? A or B: " << std::endl;
            std::cin >> setName;
            std::cout << "Enter element you want to check: " << std::endl;
            std::cin >> x;
            if (setName == 'A' || setName == 'a')
            {
                if (A.contains(x))
                {
                    std::cout << "Element " << x << " is in set A." << std::endl;
                }
                else
                {
                    std::cout << "Element " << x << " is not in set A." << std::endl;
                }
            }
            else if (setName == 'B' || setName == 'b')
            {
                if (B.contains(x))
                {
                    std::cout << "Element " << x << " is in set B." << std::endl;
                }
                else
                {
                    std::cout << "Element " << x << " is not in set B." << std::endl;
                }
            }
            else
                std::cout << "Invalid Set!!!";
            break;

        case 4:
            std::cout << "Which set do you want the size of? A or B: " << std::endl;
            std::cin >> setName;
            if (setName == 'A' || setName == 'a')
            {
                std::cout << "Set A has size " << A.size() << std::endl;
            }
            else if (setName == 'B' || setName == 'b')
            {
                std::cout << "Set B has size " << B.size() << std::endl;
            }
            else
                std::cout << "Invalid Set!!!";
            break;

        case 5:
            std::cout << "Which set do you want to see? A or B: " << std::endl;
            std::cin >> setName;
            if (setName == 'A' || setName == 'a')
            {
                std::cout << "Set A : ";
                A.display();
                std::cout << std::endl;
            }
            else if (setName == 'B' || setName == 'b')
            {
                std::cout << "Set B : ";
                B.display();
                std::cout << std::endl;
            }
            else
                std::cout << "Invalid Set!!!";
            break;

        case 6:
            C = A.intersection(B);
            std::cout << "Intersection of  A & B is: ";
            C->display();
            std::cout << std::endl;
            break;

        case 7:
            C = A.uni(B);
            std::cout << "Union of  A & B is: ";
            C->display();
            std::cout << std::endl;
            break;

        case 8:
            std::cout << "1. A-B\n2. B-A?\nEnter which one do you want to see: ";
            std::cin >> ch2;
            switch (ch2)
            {
            case 1:
                C = A.diff(B);
                std::cout << "Difference of  A & B is: ";
                C->display();
                std::cout << std::endl;
                break;
            case 2:
                C = B.diff(A);
                std::cout << "Difference of  B & A is: ";
                C->display();
                std::cout << std::endl;
                break;

            default:
                std::cout << "Invalid choice." << std::endl;
                break;
            }
            break;

        case 9:
            std::cout << "1. A subset of B\n2. B is subset of A\nEnter which one do you want to see: ";
            std::cin >> ch2;
            switch (ch2)
            {
            case 1:
                if (A.subset(B))
                {
                    std::cout << "A is a subset of B." << std::endl;
                }
                else
                {
                    std::cout << "A is not a subset of B." << std::endl;
                }
                break;
            case 2:
                if (B.subset(A))
                {
                    std::cout << "B is a subset of A." << std::endl;
                }
                else
                {
                    std::cout << "B is not a subset of A." << std::endl;
                }
                break;

            default:
                std::cout << "Invalid choice." << std::endl;
                break;
            }
            break;

        case 10:
            std::cout << "Exiting program." << std::endl;
            goto end;

        default:
            break;
        }

    } while (ch != 10);
end:
    return 0;
}
