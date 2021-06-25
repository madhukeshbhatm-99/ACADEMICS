#include <iostream>

using namespace std;

int knapSack(int W, int wt[], int profit[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n-1] > W)
        return knapSack(W, wt, profit, n-1);
    else
        return max(profit[n-1] + knapSack(W-wt[n-1], wt, profit, n-1),
                    knapSack(W, wt, profit, n-1) );
}

int main()
{
    int W, n;
    int wt[20], profit[20];
    cout << "Enter the total number of items in the bag: ";
    cin >> n;
    cout << "Enter the maximum weight that the bag can hold: ";
    cin >> W;
    cout << "Enter the weight of each item: ";
    for(int i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter the profit of each item: ";
    for(int i = 0; i < n; i++)
        cin >> profit[i];
    int result = knapSack(W, wt, profit, n);
    cout << "The solution is " << result;
    return 0;
}
