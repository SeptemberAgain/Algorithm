#include <iostream>
#include <string>
using namespace std;

//给出N对括号的所有可能

void brackets(string result, int left, int right)
{
	if (left == 0 && right==0)
	{
		cout<<result<<endl;
		return;
	}
	if (left > 0)
	{
		brackets(result+'(',left-1,right);
	}
	if (right > left)
	{
		brackets(result+')',left,right-1);
	}
}


int main()
{
	int n;
	cin>>n;
	brackets("",n,n);
	return 0;
}