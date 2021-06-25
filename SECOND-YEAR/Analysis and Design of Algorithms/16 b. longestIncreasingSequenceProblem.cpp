#include <bits/stdc++.h>

using namespace std;

int lis(int arr[], int n)
{
	int lis[n];
	lis[0] = 1;
	for(int i = 1; i < n; i++ )
	{
		lis[i] = 1;
		for(int j = 0; j < i; j++ )
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
	return *max_element(lis, lis+n);
}

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int a[n];
	cout << "Enter the elements of the array: ";
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << "The length of the longest subsequence of the given sequence is : " << lis(a,n) << endl;
	return 0;
}
