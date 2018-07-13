#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <cmath>
//Parencodings

using namespace std;
stack <int> S;
stack <int> Stemp;
int main()
{
	int N;
	cin >> N;//测试样例数目
	int n;
	for (int i = 0;i < N;i++)
	{
		cin >> n;//每个样例的个数
		int p;
		int t = 0;
		int temp,sum;
		while (!S.empty())
			S.pop();
		for (int i = 0;i < n;i++)
		{
			cin >> p;
			if (p == t)
				S.push(1);
			else
			{
				for (int j = 0;j < p - t;j++)
					S.push(-1);
				S.push(1);
				t = p;
			}
			Stemp = S;
			temp = 0;
			sum = 1;
			while ((Stemp.top() == 1) || (temp != 1))  //直到遇见相匹配的左括号为止
			{
				if (Stemp.top() == 1)
					temp++;
				else
				{
					temp--;
					sum++;
				}
				Stemp.pop();
			}
			cout << sum << ' ';
		}
	}
	return 0;
}

