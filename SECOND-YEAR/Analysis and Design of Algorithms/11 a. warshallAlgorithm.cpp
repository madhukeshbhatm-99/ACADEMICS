#include <iostream>

using namespace std;

int main()
{
    int input[10][10], v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the adjacency matrix: " << endl;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> input[i][j];
        }
    }
    int reach[10][10];
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            reach[i][j] = input[i][j];
        }
    }
    for(int k = 0; k < v; k++)
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                reach[i][j] = reach[i][j] || (reach[k][j] && reach[i][k]);
            }
        }
    }
    cout << "Following is the matrix of transitive closure: " << endl;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
           cout << reach[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
