#include <iostream>

using namespace std;

int a[20][20], visited[20], topo_order[20], m;

void dfs(int k, int v)
{
    visited[k] = 1;
    for (int i = 1; i <= v; i++)
    {
        if ((a[k][i] == 1) && (visited[i] != 1))
            dfs(i, v);
    }
    topo_order[m--] = k;
}

int main()
{
    int v, e, x, y, count = 0;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= v; i++)
        visited[i] = 0;
    m = v;
    for (int i = 1; i <= v; i++)
    {
        if (visited[i] == 0)
            dfs(i, v);
    }
    cout << "The topological sorting is " << endl;
    for (int i = 1; i <= v; i++)
        cout << topo_order[i] << " ";
    return 0;
}

