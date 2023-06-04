/* Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that. */
#include <iostream>
#include <string>

class stack
{
    int *arr, top, capacity;

public:
    stack()
    {
        capacity = 5;
        arr = new int[capacity];
        top = -1;
    }
    stack(int n)
    {
        capacity = n;
        arr = new int[capacity];
        top = -1;
    }
    bool empty();
    void push(int p);
    int pop();
};

bool stack::empty()
{
    if (top == -1)
        return 1;
    return 0;
}

void stack::push(int p)
{
    if (top == capacity - 1)
    {
        return;
    }
    top++;
    arr[top] = p;
}

int stack::pop()
{
    int t = arr[top];
    top--;
    return t;
}

struct node
{
    int data;
    node *next;
};

class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insert(int p);
};

void LinkedList::insert(int p)
{
    node *t;
    t = head;
    if (head == NULL)
    {
        t = new node;
        t->data = p;
        t->next = NULL;
        head = t;
    }
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new node;
        t->next->data = p;
        t->next->next = NULL;
    }
}

class queue
{
    int *arr, capacity, f, r;

public:
    queue()
    {
        capacity = 5;
        arr = new int[capacity];
        f = r = -1;
    }
    queue(int n)
    {
        capacity = n;
        arr = new int[capacity];
        f = r = -1;
    }
    bool empty();
    void enqueue(int p);
    int dequeue();
};

bool queue::empty()
{
    if (f == -1 && r == -1)
        return 1;
    return 0;
}

void queue::enqueue(int p)
{
    if (r == capacity - 1)
    {
        return;
    }
    if (f == -1)
    {
        f = 0;
    }
    r++;
    arr[r] = p;
}

int queue::dequeue()
{
    int t = arr[f];
    if (f == r)
    {
        f = r = -1;
    }
    else
    {
        f++;
    }
    return t;
}

class graph
{
    int noOfVertices;
    std::string *vertex;
    int **adjacencyMatrix;
    bool *visited;
    LinkedList *edgeList;

public:
    graph()
    {
        noOfVertices = 5;
        vertex = new std::string[noOfVertices];
        for (int i = 0; i < noOfVertices; i++)
        {
            std::cout << "Enter (" << i + 1 << ")th vertex data: ";
            std::cin >> vertex[i];
        }
    }
    graph(int n)
    {
        noOfVertices = n;
        vertex = new std::string[noOfVertices];
        for (int i = 0; i < noOfVertices; i++)
        {
            std::cout << "Enter (" << i + 1 << ")th vertex data: ";
            std::cin >> vertex[i];
        }
    }
    void matrixRep();
    void listRep();
    void matrixDisplay();
    void listDisplay();
    void matrixDFS(std::string v);
    void listBFS(std::string v);
};

void graph::matrixRep()
{
    adjacencyMatrix = new int *[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        adjacencyMatrix[i] = new int[noOfVertices];
        for (int j = 0; j < noOfVertices; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < noOfVertices; i++)
    {
        for (int j = i; j < noOfVertices; j++)
        {
            int edge;
            std::cout << vertex[i] << " - " << vertex[j] << " Edge value - ";
            std::cin >> edge;
            adjacencyMatrix[i][j] = edge;
            adjacencyMatrix[j][i] = edge;
        }
    }
}
void graph::matrixDisplay()
{
    for (int i = 0; i < noOfVertices; i++)
    {
        for (int j = 0; j < noOfVertices; j++)
        {
            std::cout << adjacencyMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void graph::matrixDFS(std::string v)
{
    int p;
    visited = new bool[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        visited[i] = false;
        if (vertex[i] == v)
        {
            p = i;
        }
    }
    stack s(noOfVertices);
    s.push(p);
    while (!(s.empty()))
    {
        p = s.pop();
        if (!(visited[p]))
        {
            std::cout << vertex[p] << "   " << std::endl;
            visited[p] = true;
        }
        for (int i = 0; i < noOfVertices; i++)
        {
            if (adjacencyMatrix[p][i] == 1 && !(visited[i]))
            {
                s.push(i);
            }
        }
    }
    std::cout << std::endl;
}
void graph::listRep()
{
    edgeList = new LinkedList[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        for (int j = 0; j < noOfVertices; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                edgeList[i].insert(j);
            }
        }
    }
}
void graph::listDisplay()
{
    for (int i = 0; i < noOfVertices; i++)
    {
        std::cout << vertex[i] << ":  " << std::endl;
        node *t = edgeList[i].head;
        while (t->next != NULL)
        {
            std::cout << vertex[t->data] << "->";
            t = t->next;
        }
        std::cout << vertex[t->data];
        std::cout << std::endl;
    }
}
void graph::listBFS(std::string v)
{
    int p;
    visited = new bool[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        visited[i] = false;
        if (vertex[i] == v)
        {
            p = i;
        }
    }
    queue q(noOfVertices);
    std::cout << vertex[p] << "     " << std::endl;
    visited[p] = true;
    q.enqueue(p);
    while (!(q.empty()))
    {
        p = q.dequeue();
        node *t = edgeList[p].head;
        while (t != NULL)
        {
            if (visited[t->data] == false)
            {
                std::cout << vertex[t->data] << "     " << std::endl;
                visited[t->data] = true;
                q.enqueue(t->data);
            }
            t = t->next;
        }
    }
}

int main()
{
    int n;
    std::cout << "Enter the number of vertices: " << std::endl;
    std::cin >> n;

    graph g1(n);
    g1.matrixRep();
    
    std::cout << "The matrix representation is: " << std::endl;
    g1.matrixDisplay();
    std::string vtx;
    std::cout << "\nEnter which vertex to start with for DFS: " << std::endl;
    std::getline(std::cin >> std::ws, vtx);
    g1.matrixDFS(vtx);

    std::cout << "The edge list representation is: " << std::endl;
    g1.listRep();
    g1.listDisplay();
    std::cout << "\nEnter which vertex to start with for BFS: " << std::endl;
    std::getline(std::cin >> std::ws, vtx);
    g1.listBFS(vtx);

    return 0;
}