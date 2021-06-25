#include<bits/stdc++.h>

using namespace std;

int V;
bool a[30][30];

bool isSafe (int v, bool a[][30], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (a[v][i] && c == color[i])
            return false;
    return true;
}

void printSolution(int color[])
{
    cout << "The assigned colors are: " << endl;
    for (int i = 0; i < V; i++)
      cout << color[i] << " ";
    cout << endl;
}

bool graphColor(bool a[][30], int m, int color[], int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, a, color, c))
        {
           color[v] = c;
           if (graphColor(a, m, color, v+1) == true)
             return true;
           color[v] = 0;
        }
    }
    return false;
}

int main()
{
	int m;
	cout << "Enter the number of colors: ";
	cin >> m;
	cout << "Enter the number of vertices: ";
	cin >> V;
	int color[V];
	cout << "Enter the adjacency matrix: "<<endl;
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			cin >> a[i][j];
		}
	}
   	for (int i = 0; i < V; i++)
   		color[i] = 0;
   	if (graphColor(a, m, color, 0) == false)
   	{
   		printf("Solution does not exist");
   	}
   	else
   		printSolution(color);
    	return 0;
}

