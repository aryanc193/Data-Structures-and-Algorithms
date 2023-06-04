/*
PROBLEM STATEMENT:
    You have a business with several offices; you want to lease phone lines to connect them up
    with each other; and the phone company charges different amounts of money to connect
    different pairs of cities. You want a set of lines that connects all your offices with minimum total cost.
    Solve the problem by suggesting appropriate data structures.
*/
#include <iostream>
#define MAX 999999

class tree
{
    int a[20][20], l, u, w, i, j, v, e, visited[20];

public:
    void input();
    void display();
    void minimum();
};

void tree::input()
{
    std::cout << "Enter no. of branches" << std::endl;
    std::cin >> v;
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < v; j++)
        {
            a[i][j] = MAX;
        }
    }

    std::cout << "\nEnter the no. of connections: " << std::endl;
    std::cin >> e;

    for (int i = 0; i < e; i++)
    {
        std::cout << "Enter the end branches of connections: " << std::endl;
        std::cin >> l >> u;
        std::cout << "Enter the phone company charges for this connection: " << std::endl;
        std::cin >> w;
        a[l - 1][u - 1] = a[u - 1][l - 1] = w;
    }
}

void tree::display()
{
    std::cout << "Adjacency matrix: " << std::endl;
    for (int i = 0; i < v; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < v; j++)
        {
            std::cout << a[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void tree::minimum()
{
    int p = 0, q = 0, total = 0, min;
    visited[0] = 1;
    for (int count = 0; count < (v - 1); count++)
    {
        min = MAX;
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < v; j++)
                {
                    if (visited[j] != 1)
                    {
                        if (min > a[i][j])
                        {
                            min = a[i][j];
                            p = i;
                            q = j;
                        }
                    }
                }
            }
        }
        visited[p] = 1;
        visited[q] = 1;
        total = total + min;
        std::cout << "Minimum cost connection is " << p + 1 << " -> " << q + 1 << " with charge: " << min << std::endl;
    }
    std::cout << "The total cost of connection of all branches is: " << total << std::endl;
}

int main()
{
    int ch;
    tree t;
    do
    {
        std::cout << "\n__________Prim's Algorithm__________" << std::endl;
        std::cout << "\n1. Input\n2. Display\n3. Minimum\n"
                  << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> ch;

        switch (ch)
        {
        case 1:
            std::cout << "Input the values" << std::endl;
            t.input();
            break;

        case 2:
            std::cout << "Display" << std::endl;
            t.display();
            break;

        case 3:
            std::cout << "Minimum" << std::endl;
            t.minimum();
            break;

        default:
            break;
        }
    } while (ch != 4);

    return 0;
}