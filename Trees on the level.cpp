#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
//Trees on the level

using namespace std;


int main()
{
	int i;
	int data;
	char ch;
	int max_node;
	bool complete;
	while (1)
	{
		ch = cin.get();
		if (ch == '\n')
		{
			ch = cin.get();
			if (ch == '\n')
				break;
		}
		int tree[256] = { 0 };
		max_node = 0;
		complete = true;
		if (ch == '(')
		{
			data = 0;
			while (1)
			{
				cin >> ch;
				if (ch == ')' && data == 0)
				{
					for (i = 2;i < max_node && complete;i++)
					{
						if (tree[i] > 0 && tree[i >> 1] == 0)
							complete = false;
					}
					if (!complete)
					{
						cout << "not complete" << endl;
					}
					else
					{
						for (i = 1;i <= max_node;i++)
						{
							if (tree[i] > 0)
								cout << tree[i] << ' ';
						}
					}
					cout << endl;
					break;
				}
				while (ch >= '0' && ch <= '9')
				{
					data = 10 * data + (ch - '0');
					cin >> ch;
				}
				if (ch == ',')
				{
					continue;
				}
				if (ch == 'L')
				{
					i = i << 1;
				}
				if (ch == 'R')
				{
					i = i << 1;
					i++;
				}
				if (ch == ')' && data != 0)
				{
					tree[i] = data;
					if (max_node < i)
						max_node = i;
					continue;
				}
				if (ch == '(')
				{
					data = 0;
					i = 1;
				}
			}
		}
	}
	return 0;
}

