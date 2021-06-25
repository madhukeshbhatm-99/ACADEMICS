#include <iostream>

using namespace std;

void arrange(int st[], int fi[], int n)
{
    int i, count = 0, j = 0;
    cout << "Meeting can be scheduled between " << st[0] << "PM to " << fi[0] << "PM" << endl;
    for(i = 1; i < n; i++)
    {

        if (st[i] >= fi[j])
        {
            j = j + i;
            count++;
            cout << "Meeting can be scheduled between " << st[i] << "PM to " << fi[i] << "PM" << endl;
        }
    }
    cout << "Maximum possible meetings that can be held is " << count+1 << endl;
}

void insertion_sort(int a[], int b[], int n)
{
    int i, j, item0, item1;
    for(i = 1; i <= (n-1); i++)
    {
        item0 = a[i];
        item1 = b[i];
        j = i - 1;
        while((j >= 0) && (b[j] > item1))
        {
            b[j+1] = b[j];
            a[j+1] = a[j];
            j--;
        }
        b[j+1] = item1;
        a[j+1] = item0;
    }
    cout << endl << "The meetings are:" << endl;
    for(i = 0; i < n; i++)
        cout << i+1 << ". " << a[i] << "PM to " << b[i] << "PM" << endl;
    cout << endl;
    arrange(a,b,n);
}

int main()
{
    int st[25], en[25], i, n;
    cout << "Enter the number of meetings: ";
    cin >> n;
    cout << "Enter the starting time of each meeting (PM): ";
    for(i = 0; i < n; i++)
        cin >> st[i];
    cout << "Enter the ending time of each meeting (PM):   ";
    for(i = 0; i < n; i++)
        cin >> en[i];
    insertion_sort(st,en,n);
    return 0;
}
