/* Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each key ki . Build the Binary search tree that has the least search cost given the access probability for each key */
#include <iostream>
#define MAX 10
int find(int i, int j);
void print(int, int);
int w[10][10], c[10][10], r[10][10], i, j, k, n, m;
float p[MAX], q[MAX];
char idnt[MAX][10];

int main()
{
    std::cout << "\nEnter the no of identifiers: ";
    std::cin >> n;
    std::cout << "\nEnter identifiers: ";
    for (i = 1; i <= n; i++)
    {
        std::cout << "\nIdentifier number " << i << " : ";
        std::cin >> idnt[i];
    }
    std::cout << "\nEnter success probability for identifiers: ";
    for (i = 1; i <= n; i++)
    {
        std::cout << "\np[" << i << "] : ";
        std::cin >> p[i];
    }
    std::cout << "\nEnter failure probability for identifiers: ";
    for (i = 0; i <= n; i++)
    {
        std::cout << "\nq[" << i << "] : ";
        std::cin >> q[i];
    }
    for (i = 0; i <= n; i++)
    {
        w[i][i] = q[i];
        c[i][i] = r[i][i] = 0;
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
    }
    for (m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            k = find(i, j);
            r[i][j] = k;
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
        }
    }
    std::cout << "\nRoot of this OBST: " << r[0][n] << "\tThat is\t" << idnt[r[0][n]];
    std::cout << "\nCost of this OBST: " << c[0][n];
    std::cout << "\nIn preorder";
    std::cout << std::endl;
    print(0, n);

    return 0;
}

int find(int i, int j)
{
    int min = 2000, m, l;
    for (m = i + 1; m <= j; m++)
    {
        if (c[i][m - 1] + c[m][j] < min)
        {
            min = c[i][m - 1] + c[m][j];
            l = m;
        }
    }
    return l;
}

void print(int i, int j)
{
    if (i < j)
    {
        std::cout << "\n"
                  << idnt[r[i][j]];
    }
    else
    {
        return;
    }
    print(i, r[i][j] - 1);
    print(r[i][j], j);
}