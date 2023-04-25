#include <stdio.h>

// Traversal
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// Insertion
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        printf("Insertion Failed!");
        return 0;
    }

    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        size += 1;
        display(arr, size);
        return 1;
    }
}

int indDelete(int arr[], int size, int capacity, int index)
{
    if (index > capacity)
    {
        printf("Deletion cannot be performed!");
        return 0;
    }

    else
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size -= 1;
        display(arr, size);
        return 1;
    }
}

int main()
{
    int arr[10] = {1, 2, 6, 26, 78};
    int size = 9, element = 45, index = 3;
    display(arr, size);
    indInsertion(arr, size, element, 10, index);
    indDelete(arr, size, 10, 2);

    return 0;
}
