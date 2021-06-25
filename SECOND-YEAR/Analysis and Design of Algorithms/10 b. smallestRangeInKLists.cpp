#include <bits/stdc++.h>

using namespace std;

int arr[20][20];
int ptr[501];

void findSmallestRange(int arr[][20], int n, int k)
{
	int i, minval, maxval, minrange, minel, maxel, flag, minind;
	for (i = 0; i <= k; i++)
		ptr[i] = 0;
	minrange = INT_MAX;
	while (1)
    {
        minind = -1;
		minval = INT_MAX;
		maxval = INT_MIN;
		flag = 0;
		for (i = 0; i < k; i++)
        {
            if (ptr[i] == n)
            {
				flag = 1;
				break;
			}
			if (ptr[i] < n && arr[i][ptr[i]] < minval)
			{
				minind = i;
				minval = arr[i][ptr[i]];
			}
			if (ptr[i] < n && arr[i][ptr[i]] > maxval)
			{
				maxval = arr[i][ptr[i]];
			}
		}
		if (flag)
			break;
		ptr[minind]++;
		if ((maxval - minval) < minrange)
		{
			minel = minval;
			maxel = maxval;
			minrange = maxel - minel;
		}
	}

	cout << "The smallest range is [" << minel << " " << maxel << "]";
}

int main()
{
	int k, n;
	cout << "Enter the number of lists: ";
	cin >> k;
  	cout << "Enter the size of each list: ";
	cin >> n;
	cout << "Enter the elements of the k lists: " << endl;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
   	findSmallestRange(arr, n, k);
    return 0;
}
