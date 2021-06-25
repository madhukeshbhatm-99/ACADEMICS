#include <iostream>
#include <stack>

using namespace std;

stack<int> solutionSet;
bool hasSolution;

void displaySolutionSet()
{
        stack<int> temp;
        while (!solutionSet.empty())
        {
            cout <<  solutionSet.top() << " ";
            temp.push(solutionSet.top());
            solutionSet.pop();
        }
        cout << '\n';
        while (!temp.empty())
        {
            solutionSet.push(temp.top());
            temp.pop();
        }
}

bool solve(int s, int idx, int set[],int n,int sum)
{
    if (s > sum)
        return false;
    if (s == sum)
    {
        hasSolution = true;
        displaySolutionSet();
        return false;
    }
    for(int i = idx; i < n; i++)
    {
        solutionSet.push(set[i]);
        if (solve(s+set[i], i+1, set, n, sum))
        {
            return true;
        }
        solutionSet.pop();
    }
    return false;
  }

int main()
{
	int n;
  	cout << "Enter number of elements: ";
  	cin >> n;
  	int set[n];
  	int sum;
  	cout << "Enter the sum: ";
  	cin >> sum;
  	cout << "Enter the elements of the set: ";
  	for(int i = 0; i < n; i++)
    		cin >> set[i];
    cout << "The possible subsets which yield " << sum << " are: " << endl;
   	solve(0,0,set,n,sum);
	if(hasSolution == false)
	    cout << "No Solution";
    return 0;
}
