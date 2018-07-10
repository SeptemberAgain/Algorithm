#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
//Unscrambling Images

using namespace std;
int layer[100] = { 0 };

int main()
{
	layer[1] = 0;
	layer[2] = 1;
	layer[4] = 5;
	layer[8] = 21;
	layer[16] = 85;
	int temp, index;
	int image[17][17];
	int result[17][17];
	int N, n, i, i_undetermined;
	cin >> N;//输入分块数量
	for (int k = 1;k <= N;k++)
	{
		cin >> n;//输入矩阵维度
		cin >> i;//输入元素个数
		for (int j = 0;j < i;j++)
		{
			cin >> temp >> index;
			image[index / n][index%n] = temp;
		}
		cin >> i_undetermined;
		for (int j = 0;j < i_undetermined;j++)
		{
			cin >> index >> temp;
			if (index < layer[n])
			{
				int temp_n = n;
				while (index < layer[temp_n])
				{
					temp_n /= 2;
				}
				int min_num = layer[n] + (index - layer[temp_n])*(n / temp_n)*(n / temp_n);
				int max_num = min_num + (n / temp_n)*(n / temp_n);
				for (int p = 0;p < n;p++)
				{
					for (int q = 0;q < n;q++)
					{
						if (image[p][q] >= min_num && image[p][q] < max_num)
							result[p][q] = temp;
					}
				}
			}
			else
			{
				for (int p = 0;p < n;p++)
				{
					for (int q = 0;q < n;q++)
					{
						if (image[p][q] == index)
							result[p][q] = temp;
					}
				}
			}
		}
		cout << "Case " << k << endl << endl;
		for (int p = 0;p < n;p++)
		{
			for (int q = 0;q < n;q++)
			{
				cout << result[p][q] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}

