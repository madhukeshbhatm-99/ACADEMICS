#include <bits/stdc++.h>

using namespace std;

int recursive_binary(int a[], int n, int beg, int end, int 

key)
{
    if (beg <= end)
    {
        int mid;
        mid = (beg + end) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return recursive_binary(a, n, beg, mid-1, key);
        else
            return recursive_binary(a, n, mid+1, end, key);
    }
    else
        return -1;
}

int main()
{
    clock_t time;
    int a[25], n, key;
    int beg, end, pos;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the sorted array elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the element to be searched: ";
    cin >> key;
    beg = 0;
    end = n - 1;
    time = clock();
    pos = recursive_binary(a, n, beg, end, key);
    if (pos == -1)
        cout << "The key is not present!" << endl;
    else
        cout << "The key is found at the position " << pos + 1 << endl;
    time = clock() - time;
    cout << "Total processor time required to compute the recursive search is " << (double)time/CLOCKS_PER_SEC << "s";
    return 0;
}
