#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // swap A[i] and A[indexOfMin]
        int temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    int A[] = {12, 54, 65, 7, 23, 9};
    int n1 = 6;

    printArray(A, n1);
    selectionSort(A, n1);
    printArray(A, n1);
    return 0;
}