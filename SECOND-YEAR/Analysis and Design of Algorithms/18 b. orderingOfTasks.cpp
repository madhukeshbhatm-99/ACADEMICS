#include <bits/stdc++.h>
#include <utility>

using namespace std;

stack<int> s;
int n, a[30][30], q[30], f=0, r=-1;

void lextopo()
{
	vector<int> indeg(n,0);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
				indeg[j]++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if (indeg[i] == 0)
			q[++r] = i;
	}
	int c = 0;
	vector<int> toporder;
	while(f <= r)
	{
		int minimum = q[f++];
		toporder.push_back(minimum);
		for(int i = 0; i < n; i++)
		{
			if (a[minimum][i] == 1)
			{
				indeg[i]--;
				if (indeg[i]==0)
					q[++r] = i;
			}
		}
		c++;
	}
	if (c != n)
	{
		cout << -1 << endl;
		return;
	}
	for(int i = 0; i < toporder.size(); i++)
		cout << toporder[i] << " ";
}

int main()
{
	int p, x, y;
	vector<pair<int, int>> pre;
	cout << "Enter the number of tasks: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			a[i][j] = 0;
	}
	cout << "Enter the number of pairs: ";
	cin >> p;
	cout << "Enter the pairs: " << endl;
	for(int i = 0; i < p; i++)
	{
		cin >> x >> y;
		pre.push_back(make_pair(x, y));
		a[y][x]=1;
	}
	cout << "The ordering of tasks you should pick to finish all tasks: "<<endl;
	lextopo();
	return 0;
}
