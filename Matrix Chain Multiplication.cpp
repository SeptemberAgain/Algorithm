#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;
//给出回文构词法的堆栈实现

struct Node
{
	int row,col;
};

map<char, Node>matrix;


int main()
{
	char name;
	string dest;
	int n;
	cin>>n;
	for (int i =0;i<n;i++)
	{
		cin>>name;
		cin>>matrix[name].row>>matrix[name].col;
	}
	while (cin>>dest)
	{
		stack<Node>method;
		unsigned int i;
		int count=0;
		for (i=0;i<dest.size();i++)
		{
			if (dest[i]=='(')
			{
				continue;
			}
			else if (dest[i]==')')
			{
				Node a=method.top();
				method.pop();
				Node b=method.top();
				method.pop();
				if (a.row != b.col)
				{
					cout<<"error"<<endl;
					break;
				}
				else
				{
					count += a.col * a.row * b.row;
					Node temp = {b.row, a.col};
					method.push(temp);
				}
			}
			else
			{
				method.push(matrix[dest[i]]);
			}
			if (i==dest.size())
			{
				cout<<count<<endl;
			}
		}
	}
	return 0;
}