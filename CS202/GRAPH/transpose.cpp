#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class graph
{
public:
    int matrix[100][100];
    unordered_map<int, list<int>> adj;

    // Create Adjacency List
    void take_adjacency_list_vertix()
    {
        int m;
        cout << "\nEnter the number of edges : ";
        cin >> m;
        cout << "\nEnter adjacent vertices :\n";
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            // Create Adjacency List for directed graph
            adj[u].push_back(v);
        }
    }

    // Print Adjacency List
    void print_adjacency_list()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << "\n";
        }
    }

    // Transpose Adjacency List
    void transpose_adjacency_list()
    {
    }

    // Create Adjacency Matrix
    void take_adjacency_matrix_vertix(int n)
    {
        cout << "\nEnter " << n << " * " << n << " matrix for adjacency matrix :\n  ";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "\n"
                 << i + 1 << "| ";
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    // Print Adjacency Matrix
    void print_adjacency_matrix(int n)
    {
        cout << "  ";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1;
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << "\n"
                 << i + 1 << "| ";
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Transpose Adjacency matrix
    void transpose_adjacency_matrix(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i <= j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }
};
int main()
{
    graph g;
    int n;
    int choice;
    cout << "\nPress 1 to create graph using adjacency list. ";
    cout << "\nPress 2 to create graph using adjacency matrix. ";
    cout << "\nPress 3 to print adjacency list. ";
    cout << "\nPress 4 to print adjacency matrix. ";
    cout << "\nPress 5 to transpose adjacency list. ";
    cout << "\nPress 6 to transpose adjacency matrix. ";
    cout << "\nPress 7 to end the program. ";
    while (1)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.take_adjacency_list_vertix();
            break;

        case 2:
            cout << "\nEnter the number of nodes : ";
            cin >> n;
            g.take_adjacency_matrix_vertix(n);
            break;

        case 3:
            cout << "\nGraph is : \n";
            g.print_adjacency_list();
            break;

        case 4:
            cout << "\nGraph is : \n";
            g.print_adjacency_matrix(n);
            break;

        case 5:
            g.transpose_adjacency_list();
            break;
        case 6:
            g.transpose_adjacency_matrix(n);
            break;
        case 7:
            cout << "\nProgram Ended !";
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}