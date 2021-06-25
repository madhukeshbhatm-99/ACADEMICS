#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int graph[20][20];
    bool visited[20];
    int v, e, x, y;
    queue <int> q;
    cout << "Enter the number of edges and vertices: ";
    cin >> e >> v;
    while(e != 0)
    {
        cout << "The edges are connected between ";
        cin >> x >> y;
        e--;
        graph[x][y] = 1;
    }
    cout << "Enter the initial vertex: ";
    cin >> x;
    visited[x] = true;
    q.push(x);
    cout << "The BFS traversal is: " << endl;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        cout << x << "  ";
        for(int k = 1; k <= v; k++)
        {
            if (graph[x][k] && !visited[k])
            {
                q.push(k);
                visited[k] = true;
            }
        }
    }
    return 0;
}
