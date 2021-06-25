#include <iostream>

using namespace std;

bool convertToBinary(int n)
{
    int binsum = 0, bin[32], i = 0;
    cout << "The binary of " << n << " is ";
    while (n != 0)
    {
        bin[i] = n % 2;
        n /= 2;
        i++;
    }
    for(int j = i - 1; j >= 0; j--)
    {
        cout << bin[j];
        binsum += bin[j];
    }
    cout << endl;
    if (binsum % 2)
        return 0;
    else
        return 1;
}

void sumNum(int num)
{
    int sum = 0, res = 0;
    if (convertToBinary(num))
    {
        while(num != 0)
        {
            res = num % 10;
            sum += res;
            num /= 10;
        }
    }
    if (sum)
        cout << "The sum of digits is: " << sum;
    else
        cout << "Not allowed (Odd number of 1's)";
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    sumNum(num);
    return 0;
}
