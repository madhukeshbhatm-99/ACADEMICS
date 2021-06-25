#include <iostream>
#include <time.h>

using namespace std;

void mergeSort(int a[], int low, int mid, int high)
{
    int s[20];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            s[k] = a[i];
            i++;
            k++;
        }
        else
        {
            s[k] = a[j];
            j++;
            k++;
        }
    }
    while(j <= high)
    {
       s[k] = a[j];
       j++;
       k++;
    }
    while(i <= mid)
    {
       s[k] = a[i];
       i++;
       k++;
    }
    for(i = low, j = 0; i <= high; i++,j++)
        a[i] = s[j];
}

void divide(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        divide(a, low, mid);
        divide(a, mid + 1, high);
        mergeSort(a, low, mid, high);
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
    divide(arr, low, high);
    time = time - start;
    cout << "The sorted array is: ";
    for(int m = 0; m < n; m++)
        cout << arr[m] << " ";
    cout << "\nProcessor time required is " << (double)time / CLOCKS_PER_SEC << "s";
    return 0;
}
