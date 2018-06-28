#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>
//trees made to order
using namespace std;

typedef struct
{
	int a; 
	int b;
}pack;

int catalan(int n)
{
	if (n<=1)
	{
		return 1;
	}
	else
	{
		int temp = 0;
		for(int i = 0;i<n;i++)
		{
			temp += catalan(i)*catalan(n-1-i);
		}
		return temp;
	}
}

pack sequence(int num)
{
	pack temp;
	temp.a = 1;
	temp.b = 0;
	while (1)
	{
		temp.b += catalan(temp.a);
		if (num<temp.b)
		{
			temp.b = num - (temp.b-catalan(temp.a));
			break;
		}
		temp.a++;
	}
	return temp;
}


void handletree(int num,int seq)
{
	if (num == 1)
	{
		cout<<'X';
		return;
	}
	if (num ==0)
		return;
	int right,left,treetemp;
	right = num - 1;
	for (left = 0;left<num;left++,right--)
	{
		treetemp = catalan(left)*catalan(right);
		if(seq>treetemp)
			seq -= treetemp;
		else
			break;
	}
	seq--;
	if(left!=0)
	{
		cout<<'(';
		handletree(left,(seq/catalan(right))+1);
		cout<<')';
	}
	cout<<'X';
	if (right!=0)
	{
		cout<<'(';
		handletree(right,(seq%catalan(right))+1);
		cout<<')';
	}
}


int main()
{
	int number;
	cin>>number;
	int dot = sequence(number).a;
	int seq = sequence(number).b;
	cout<<dot<<' '<<seq;
	handletree(dot,seq);
	return 0;
}



