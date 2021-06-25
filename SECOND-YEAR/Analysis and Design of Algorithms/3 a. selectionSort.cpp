#include <iostream>
#include <time.h>

using namespace std;

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
    cout <<  "Sorted array is : ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10], n;
    clock_t first, last;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    first = clock();
    selection_sort(n, arr);
    last = clock();
    cout << "Processor time required is: " << double(first - last) / CLOCKS_PER_SEC << "s";
    return 0;
}
