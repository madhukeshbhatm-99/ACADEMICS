#include <iostream>

using namespace std;

int a[10][10], k, indegree[10], temp[10];

void topo(int v)
{
    k = 0;
    for(int i = 1; i <= v; i++)
    {
        if(indegree[i] == 0)
        {
            indegree[i] = 1;
            temp[++k] = i;
            for(int j = 1; j <= v; j++)
            {
                if((a[i][j] == 1) && (indegree[j] != -1))
                {
                    indegree[j]--;

                }
            }
            i=0;
        }
    }
}

int main()
{
    int v;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the adjacency matrix : " << endl;
    for(int i = 0; i <= v; i++)
    {
        indegree[i] = 0;
    }
    for(int i = 1; i <= v; i++)
        for(int j = 1; j <= v; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
                indegree[j]++;
        }
    topo(v);
    if(k != v)
        cout << "There is no topological ordering";
    else
    {
        for (int i = 1; i <= v;i++)
            cout << temp[i] << " ";
    }
    return 0;
}
