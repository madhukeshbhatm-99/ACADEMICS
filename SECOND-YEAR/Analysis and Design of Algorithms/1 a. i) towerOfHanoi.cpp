#include <iostream>

using namespace std;

void tower_of_hanoi(int, char, char, char);

int count = 0;

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    cout << "The transitions are: " << endl;
    tower_of_hanoi(n, 'X', 'Y', 'Z');
    cout << "The number of shifts are " << count;
    return 0;
}

void tower_of_hanoi(int n, char source, char dest, char temp)
{
    if (n != 0)
    {
        tower_of_hanoi(n-1, source, temp, dest);
        cout << source << " moves to " << temp << endl;
        tower_of_hanoi(n-1, temp, dest, source);
        count++;
    }
}
