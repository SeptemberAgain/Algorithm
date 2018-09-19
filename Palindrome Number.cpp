#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
//Palindrome Number
using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int intial = x;
		int temp = 0;
		while (x > 0)
		{
			temp = temp * 10 + x % 10;
			x /= 10;
		}
		return (intial == temp) ? true : false;
	}
};
int main()
{
	int my;
	cin >> my;
	Solution A;
	cout << A.isPalindrome(my);
	return 0;
}