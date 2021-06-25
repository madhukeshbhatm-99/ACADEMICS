#include <iostream>
using namespace std;

int longestSeq(string s, int i, int j)
{
	if(i == j)
		return 1;
	else if(s[i] == s[j] && i+1 == j)
		return 2;
	else if(s[i] == s[j])
		return longestSeq(s, i+1 ,j-1) + 2;
	else
		return max(longestSeq(s, i+1, j), longestSeq(s, i, j-1));
}

int main()
{
	string s;
	cout << "Enter the sequence: ";
	getline(cin, s);
	cout << "The length of the longest palindromic subsequence is : " << longestSeq(s, 0, s.length()-1);
	return 0;
}
