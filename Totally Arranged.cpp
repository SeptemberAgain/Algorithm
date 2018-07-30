#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
//Totally Arranged

using namespace std;
void Perm(int list[], int m, int n)
{
	if (n == m)
	{
		for (int i = 0;i<=n;i++)
			cout<<i<<" ";
		cout<<endl;
	}
	else
	{
		for(int j = 0;j<n;j++)
		{
			swap(list[m], list[j]);
			Perm(list, m+1, n);
			swap(list[j], list[m]);
		}
	}
}

int main()
{
	int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Perm(list, 1, 1);
	return 0;
}

