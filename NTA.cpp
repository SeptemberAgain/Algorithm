#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>
//NTAÀ„∑®

using namespace std;
int max_number;
int number;
char tree[100];
int n, m, k;

struct signal
{
	int left;
	int right;
};

vector<signal>table[10][10];

void create_table(int n, int k)
{
	signal pair;
	char table_temp;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < k;j++)
		{
			table[i][j].clear();
			while (true)
			{
				cin >> pair.left;
				cin >> pair.right;
				table[i][j].push_back(pair);
				table_temp = getchar();
				if (table_temp == '\n')
					break;
			}
		}
	}
}

void create_tree()
{
	char tree_temp;
	number = 0;
	for (int i = 0;i <= max_number;i++)
	{
		for (int j = 0;j < (1 << i);j++)
		{
			cin >> tree_temp;
			tree[number] = tree_temp;
			number++;
		}
	}
}

bool judge(int insignal, int node)
{
	int insignal1, insignal2;
	if (tree[node] == '*' || node >= number)
		if (insignal < n - m)
			return false;
		else
			return true;
	int x = tree[node] - 'a';
	int dleft = node * 2 + 1;
	int dright = dleft + 1;
	for (int i = 0;i < table[insignal][x].size();i++)
	{
		insignal1 = table[insignal][x][i].left;
		insignal2 = table[insignal][x][i].right;
		if (judge(insignal1, dleft) && judge(insignal2, dright))
			return true;
	}
	return false;
}

int main()
{
	cin >> n;
	cin >> m;
	cin >> k;
	create_table(n, k);
	while ((cin >> max_number) && (max_number != -1))
	{
		create_tree();
		if (judge(0, 0))
			cout << "Valid" << endl;
		else
			cout << "Invalid" << endl;
	}
	return 0;
}



