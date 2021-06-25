#include <iostream>

using namespace std;

int euclid(int m, int n)
{
    int rem;
    while (n != 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int rep_sub(int m, int n)
{
    while (m != n)
    {
        if (m > n)
            m = m - n;
        else
            n = n - m;
    }
    return m;
}

int cons_int(int m, int n)
{
    int small;
    if (m > n)
        small = n;
    else
        small = m;
    while(1)
    {
        if (m % small == 0 && n % small == 0)
            return small;
        else
            small--;
    }
}

int mid_school(int m, int n)
{
    int large;
    large = m > n ? m : n;
    int a = 0, b = 0, result = 1;
    for(int i = 2; i <= large; i++)
    {
        a = 0;
        b = 0;
        if (m % i == 0)
        {
            a = 1;
            m = m / i;
        }
        if (n % i == 0)
        {
            b = 1;
            n = n / i;
        }
        if (a == 1 && b == 1)
            result*=i;
        if (a == 1 || b == 1)
            i--;
    }
    return result;
}

int main()
{
    int a, b, result;
    cout << "Enter two non-zero numbers: ";
    cin >> a >> b;
    result = euclid(a, b);
    cout << endl << "The GCD of " << a << " and " << b << " using Euclid's method is " << result << endl;
    result = rep_sub(a, b);
    cout << "The GCD of " << a << " and " << b << " using the method of repetitive subtraction is " << result << endl;
    result = cons_int(a, b);
    cout << "The GCD of " << a << " and " << b << " using the method of consecutive integer checking is " << result << endl;
    result = mid_school(a, b);
    cout << "The GCD of " << a << " and " << b << " using middle school's method is " << result << endl;
    return 0;
}
