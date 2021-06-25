]#include <iostream>
#include <time.h>

using namespace std;

int linear_recursion(int a[], int i, int n, int key)
{
    if (i < n)
    {
        if (a[i] == key)
            return i;
        else
            return linear_recursion(a, i+1, n, key);
    }
    else
        return -1;
}

int main()
{
    int a[30], pos, j = 0, n, key;
    clock_t start, end;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the key element: ";
    cin >> key;
    start = clock();
    pos = linear_recursion(a, j, n, key);
    if (pos == -1)
        cout << "Element not found! " << endl;
    else
        cout << "Element found at position " << (pos+1) << endl;
    end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Processor time required is " << time << "s";
    return 0;
}
