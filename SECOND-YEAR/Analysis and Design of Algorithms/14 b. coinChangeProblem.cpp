#include <iostream>

using namespace std;

void findMin(int cost, int coins[10], int n)
{
    int coinList[20] = { 0 };
    int i, k = 0;

    for (i = n - 1; i >= 0; i--) {
        while (cost >= coins[i]) {
            cost -= coins[i];
            coinList[k++] = coins[i];
        }
    }

    for (i = 0; i < k; i++) {
        cout << coinList[i] << " ";
    }
}

int main(void)
{
    int coins[10];
    int n, amt, i;
    cout << "Enter number of denominations: ";
    cin >> n;
    cout << "Enter the denominations available: ";
    for(i = 0; i < n; i++)
        cin >> coins[i];
    cout << "Enter amount to be found for change: ";
    cin >> amt;
    cout << "Following is minimal number of change for " << amt << ": ";
    findMin(amt, coins, n);
    return 0;
}
