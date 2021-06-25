#include<iostream>
#include<chrono>

using namespace std::chrono;
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		a[i] = rand() % n;
        cout << "The random array is: ";
        for(int i = 0; i < n; i++)
		cout << a[i] << " ";
        auto start = high_resolution_clock::now();
	heapSort(a, n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast <microseconds>(stop - start);
	cout << "Sorted array is: "<<endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "Time taken: " << duration.count() << " microseconds" << endl;
	return 0;
}
