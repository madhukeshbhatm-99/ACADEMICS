#include <iostream>
#include <time.h>

using namespace std;

int partitionArr(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    while(1)
    {
        while(a[i] <= pivot && i <= high)
            i++;
        while(a[j] > pivot && j >= low)
            j--;
        if (i < j)
            swap(a[i], a[j]);
        else
        {
            a[low] = a[j];
            a[j] = pivot;
            return j;
        }
    }
}

void quickSort(int a[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitionArr(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
    else
        return;
}

int main()
{
    clock_t start;
    int time;
    int arr[20], i, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the values: ";
    for(i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0;
    int high = n - 1;
    start = clock();
    quickSort(arr, low, high);
    time = time - start;
    cout << "The sorted array is: ";
    for(int m = 0; m < n; m++)
        cout << arr[m] << " ";
    cout << "\nProcessor time required is " << (double)time / CLOCKS_PER_SEC << "s";
    return 0;
}
