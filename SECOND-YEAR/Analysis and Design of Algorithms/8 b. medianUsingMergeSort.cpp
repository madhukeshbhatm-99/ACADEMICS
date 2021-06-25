#include <iostream>

using namespace std;

void median(int t, int arr[])
{
    double median;
    cout << "The median is: ";
    if (t % 2 == 0)
    {
        median = (arr[t/2] + arr[t/2 - 1]) / 2.0;
        cout << median;
    }
    else
    {
        median = arr[t/2];
        cout << median;
    }
}

void mergeSort(int a[], int b[], int n, int m)
{
    int s[20];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m)
    {
        if (a[i] < b[j])
        {
            s[k] = a[i];
            i++;
            k++;
        }
        else
        {
            s[k] = b[j];
            j++;
            k++;
        }
    }
    while(j < m)
    {
       s[k] = b[j];
       j++;
       k++;
    }
    while(i < n)
    {
       s[k] = a[i];
       i++;
       k++;
    }
    cout << "The sorted array is: ";
    for(i = 0; i < (n + m); i++)
        cout << s[i] << " ";
    cout << endl;
    median((n + m), s);
}

int main()
{
    int arr1[20], arr2[20], i, n, m;
    cout << "Enter the number of elements in first sorted array: ";
    cin >> n;
    cout << "Enter the number of elements in second sorted array: ";
    cin >> m;
    cout << "Enter the values in first sorted array: ";
    for(i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter the values in second sorted array: ";
    for(i = 0; i < m; i++)
        cin >> arr2[i];
    mergeSort(arr1, arr2, n, m);
    return 0;
}
