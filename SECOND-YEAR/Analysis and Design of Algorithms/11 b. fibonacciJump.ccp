#include <iostream>

using namespace std;

void fib(int arr[], int  n)
{
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < n; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}
}

int jump(bool arr[], int n, int fib[])
{
	int temp[n+2];
	temp[0] = 0;
	int test;
	for(int i = 1; i < n+2; i++)
		temp[i] = (INT_MAX - 1);

	for(int i = 1; i <= n+1; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if ((arr[i-1] == 1 || i == n+1) && (i - fib[j] >=0))
			{
				test = 1 + temp[i-fib[j]];
				if (test < temp[i])
				temp[i] = test;
			}
		}
	}
	if (temp[n+1] == INT_MAX - 1)
	return -1;
	else
        return temp[n+1];
}

int main()
{
	cout << "Enter the size of the array: ";
	int size;
	cin >> size;
	bool arr[size];
	cout << "Enter the values: " << endl;
	for(int i = 0; i < size; i++)
	{
		cout << i << ": ";
		cin>> arr[i];
	}
	int Fibonacci[size];
	fib(Fibonacci, size);
	cout << "The minimum jumps possible is " << jump(arr, size, Fibonacci);
}
