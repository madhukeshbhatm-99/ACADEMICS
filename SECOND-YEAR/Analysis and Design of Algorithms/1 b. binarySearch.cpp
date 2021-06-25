#include <iostream>

using namespace std;

int main()
{
    int n, a[50];
    int beg, end, mid, key;
    int posl, posr, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements in sorted order: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the element to be searched: ";
    cin >> key;
    beg = 0;
    end = n - 1;
    mid = (beg + end) / 2;
    while (beg <= end)
    {
        if (a[mid] == key)
        {
            posr = mid + 1;
            posl = mid - 1;
            while (a[posr] == key)
                posr++;
            posr--;
            while (a[posl] == key)
                posl--;
            posl++;
            cout << "Key element is found " << (posr - posl + 1) << " times";
            cout << " between the positions " << (posl + 1) << " and " << (posr + 1);
            return 0;
        }
        else if (a[mid] < key)
            beg = mid + 1;
        else
            end = mid - 1;
        mid = (beg + end) / 2;
    }
    if (beg > end)
        cout << -1;
    return 0;
}
