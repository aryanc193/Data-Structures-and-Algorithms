#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int B[] = {1, 2, 4, 7, 9, 12};
    int n1 = 6;
    int C[] = {122, 233, 41, 75, 9, 121, 69, 420, 58, 42, 28, 1, 14};
    int n2 = 13;
    printf("\nArray A\n");
    printArray(A, n1);
    bubbleSortAdaptive(A, n1);
    printArray(A, n1);
    printf("\nArray B\n");
    printArray(B, n1);
    bubbleSortAdaptive(B, n1);
    printArray(B, n1);
    printf("\nArray C\n");
    printArray(C, n2);
    bubbleSort(C, n2);
    printArray(C, n2);
    return 0;
}