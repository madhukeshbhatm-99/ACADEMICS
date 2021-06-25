#include <iostream>
#include <cstring>

using namespace std;

int minimum(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    else
        return z;
}

int minOperations(char a[], char b[], int k, int l)
{
    if (k == 0)
        return l;
    if (l == 0)
        return k;
    if (a[k-1] == b[l-1])
        return minOperations(a, b, k-1, l-1);
    else
        return 1 + minimum(minOperations(a, b, k-1, l), minOperations(a, b, k, l-1), minOperations(a, b, k-1, l-1));
}

int main()
{
    char str1[20], str2[20];
    int len1, len2;
    cout << "Enter first string: ";
    cin >> str1;
    len1 = strlen(str1);
    cout << "Enter second string: ";
    cin >> str2;
    len2 = strlen(str2);
    int result = minOperations(str1, str2, len1, len2);
    cout << "The minimum operations possible is " << result;
    return 0;
}
