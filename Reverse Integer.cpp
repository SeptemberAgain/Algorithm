#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
//Reverse Integer
using namespace std;


class Solution {
public:
	int reverse(int x) {
		int result = 0;
		int temp;
		while (x != 0)
		{
			temp = result*10 + x % 10;
			if (temp / 10 != result) return 0;
			result = temp;
			x /= 10;
		}
		return result;
	}
};

int main()
{
	int myint;
	cin >> myint;
	Solution A;
	cout << A.reverse(myint);
	return 0;
}