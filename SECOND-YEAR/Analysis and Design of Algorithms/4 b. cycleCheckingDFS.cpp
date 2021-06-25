#include <iostream>

using namespace std;

int a[20][20], visited[20];
bool bulb = false;

void dfs(int k, int v)
{
    visited[k] = 1;
    for (int i = 1; i <= v; i++)
    {
        if ((a[k][i] == 1) && (visited[i] == 1))
        {
            bulb = true;
            break;
        }
        if ((a[k][i] == 1) && (visited[i] != 1))
        {
            cout << k << " -> " << i << endl;
            dfs(i, v);
        }
    }
}

int main()
{
    int v, e, x, y;
    cout << "Enter the number of edges and vertices: ";
    cin >> e >> v;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j < v; j++)
        {
            visited[i] = 0;
            a[i][j] = 0;
        }
    }
    cout << "Enter the end vertices of each edge " << endl;
    while (e != 0)
    {
        cout << "Connected between: ";
        cin >> x >> y;
        a[x][y] = 1;
        e--;
    }
    if (bulb == true)
        cout << "Cycle exists";
    else
        cout << "Cycle do not exists";
    return 0;
}
