#include <iostream>
#include <vector>
//Code the tree

using namespace std;

const int n = 50;
vector<int> temp;
vector<int> mytree[50];
int flag = 0;
int i = 0;

void getinput()
{
	char ch;
	while (1)
	{
		ch = cin.get();
		if (ch == '\n')
			break;
		if (ch == '(')
			flag = 0;
		else if (ch <= '9' && ch >= '0')
			temp.push_back(ch - '0');
		else if (ch == ')')
		{
			if (flag == 0)
			{
				mytree[i] = temp;
				i++;
			}
			temp.pop_back();
			flag = 1;
		}
	}
	return;
}
int main()
{
	getinput();
	int min;
	int remain;
	int sum;
	int valid;
	while (1)
	{
		sum = 0;
		for (int j = 0;j < i;j++)
		{
			if (mytree[j].size() > 1)
			{
				remain = j;
				sum++;
			}
		}
		if (sum <= 1)
			break;
		min = mytree[remain].back();
		for (int j = 0;j < i;j++)
		{
			if ((mytree[j].size() > 1) && (min > mytree[j].back()))
			{
				valid = 1;
				for (int k = 0;k < i;k++)
				{
					if ((mytree[j].size() < mytree[k].size()) && (mytree[j].back() == mytree[k].at(mytree[j].size() - 1)))
					{
						valid = 0;
						break;
					}
				}
				if (valid == 1)
				{
					min = mytree[j].back();
				}
			}
		}
		flag = 0;
		for (int j = 0;j < i;j++)
		{
			if ((mytree[j].size() > 1) && (min == mytree[j].back()))
			{
				mytree[j].pop_back();
				if (flag == 0)
				{
					cout << mytree[j].back() << ' ';
					flag = 1;
				}
			}
		}
	}
	while (mytree[remain].size() > 1)
	{
		if (mytree[remain].front() < mytree[remain].back())
		{
			mytree[remain].erase(mytree[remain].begin());
			cout << mytree[remain].front() << ' ';
		}
		else
		{
			mytree[remain].pop_back();
			cout << mytree[remain].back() << ' ';
		}
	}
	return 0;
}



