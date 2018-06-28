#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
//给出回文构词法的堆栈实现
stack<char>temp;
vector<char>cap;
vector<char>::iterator p;
string a,b;

void anagram(int num_push, int num_pop, int word_length)
{
	if (num_pop == word_length)
	{
		for (p=cap.begin();p!=cap.end();++p)
		{
			cout<<*p<<" ";
		}
		cout<<endl;
	}
	if ((num_push+1)<=word_length)
	{
		temp.push(a[num_push]);
		cap.push_back('i');
		anagram(num_push+1,num_pop,word_length);
		temp.pop();
		cap.pop_back();
	}
	if ((num_push>num_pop)&&(temp.top()==b[num_pop]))
	{
		char c = temp.top();
		temp.pop();
		cap.push_back('o');
		anagram(num_push,num_pop+1,word_length);
		temp.push(c);
		cap.pop_back();
	}
}


int main()
{
	cin>>a>>b;
	cout<<'['<<endl;
	anagram(0,0,a.length());
	cout<<']';
	return 0;
}