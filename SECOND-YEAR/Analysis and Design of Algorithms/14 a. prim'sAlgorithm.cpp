#include<bits/stdc++.h>

using namespace std;

int a[30][30], visited[30], n, totwt = 0, c = 0;

void prim(int v)
{
	int indi, indj;
	visited[v] = 1;
	int min = 10000000;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(visited[i] == 1 && visited[j] == 0)
			{
				if(a[i][j] < min)
				{
					min = a[i][j];
					indi = i;
					indj = j;
				}
			}
		}
	}
	totwt = totwt + a[indi][indj];
	cout << indi << " to " << indj << "\t " << a[indi][indj] << endl;
	c++;
	visited[indj] = 1;
	if(c == n - 1)
		return;
	prim(indj);
}

int main()
{
	cout << "Enter the number of vertices: ";
	cin >> n;
	cout << "Enter the weighted matrix (Enter 9999 for infinity)" << endl;
	for(int i = 1; i <= n; i++)
	{
		visited[i] = 0;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl << "Minimum spanning tree is: " << endl;
	cout << "Edges \t Weights" <<endl;
	prim(1);
	cout << "Minimum cost = " << totwt << endl;
	return 0;
}
