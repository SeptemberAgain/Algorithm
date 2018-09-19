#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
//String To Integer
using namespace std;


class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int n = str.size();
		int sign = 1;
		int i = 0;
		while (i < n && str[i] == ' ') i++;
		if (i == n) return 0;
		int number = 0;
		if (str[i] == '-' || str[i] == '+')
		{
			sign = (str[i] == '-') ? -1 : 1;
			i++;
		}
		if (str[i] < '0' || str[i] > '9') return 0;
		while (i < n && str[i] >= '0' && str[i] <= '9')
		{
			if ((number > INT_MAX / 10) || (number == INT_MAX / 10 && str[i] - '0'>7)) return (sign == 1) ? INT_MAX : INT_MIN;
			number = number * 10 + str[i] - '0';
			i++;
		}
		return number *sign;
	}
};

int main()
{
	string my;
	cin >> my;
	Solution A;
	cout << A.myAtoi(my);
	return 0;
}