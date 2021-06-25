#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int arr[n][n];
    int x = 0;
    for (int i = 0; i < n / 4; i++)
    {
        for (int j = 0; j < n / 4; j++)
        {
             for (int k = 0; k < 4; k++)
             {
                  for (int l = 0; l < 4; l++)
	{
            	    arr[i * 4 + k][j * 4 + l] = x;
            	    x++;
                 }
            }
        }
    }
    cout << "The grid is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        { 
             cout << arr[i][j] << "  ";
             cout << endl;
         }
    }
    return 0;
}
