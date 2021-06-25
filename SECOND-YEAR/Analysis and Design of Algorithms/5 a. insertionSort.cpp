#include <iostream>
#include <time.h>

using namespace std;

void insertion_sort(int a[], int n)
{
    int i, j, item;
    for(i = 1; i <= (n-1); i++)
    {
        item = a[i];
        j = i - 1;
        while((j >= 0) && (a[j] > item))
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = item;
    }
    cout << "Array after insertion sort: ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[25], i,n;
    clock_t begin, end;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for(i = 0; i < n; i++)
        cin >> a[i];
    begin = clock();
    insertion_sort(a,n);
    end = clock();
    cout << "Processor time required is " << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
