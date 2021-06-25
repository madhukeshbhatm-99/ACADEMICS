#include<iostream>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		cout << "Please enter source file and destination file\n";
		return 0;
	}
	if(link(argv[1], argv[2]) == -1)
	{
		cout << "Can't Link " << argv[1] << " and " << argv[2] << "\n";
		return 1;
	}
	else
		cout<<"Files have been Linked\n";
	return 0;
}
