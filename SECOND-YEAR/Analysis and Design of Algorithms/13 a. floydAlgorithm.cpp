#include <iostream>

using namespace std;

int main()
{
    int input[10][10], v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the distance matrix: " << endl;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> input[i][j];
        }
    }
    int graph[10][10];
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            graph[i][j] = input[i][j];
        }
    }
    for(int k = 0; k < v; k++)
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    cout << "Following is the matrix of shortest distances between each pair of vertices: " << endl;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            if (graph[i][j] == 999)
               cout << "INF ";
            else
               cout << graph[i][j] << " ";
        }
       cout << endl;
    }
    return 0;
}
