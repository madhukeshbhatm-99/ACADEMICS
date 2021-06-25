#include <iostream>

using namespace std;

void printLargest(int arr[], int m)
{
    int k;
    cout << "Enter the value of k to find kth largest number: ";
    cin >> k;
    cout << "The " << k << " largest number in the array is: " << arr[m-k];
}

void selection_sort(int n, int a[])
{
    int pos, small;
    int i, j;
    for(i = 0; i < n-2; i++)
    {
        pos = i;
        small = a[i];
        for(j = i+1; j < n-1; j++)
        {
            if (a[j] < small)
            {
                small = a[j];
                pos = j;
            }
        }
        int temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }
    printLargest(a, n);
}

int main()
{
    int arr[10], n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the distinct array elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    selection_sort(n, arr);
    return 0;
}
