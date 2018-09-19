#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
//Regular Expression Matching
using namespace std;


class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		else
		{
			if (p.size() > 1 && p[1] == '*')
				return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
			else
				return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
	}
};

int main()
{
	string my, my2;
	cin >> my;
	cin >> my2;
	Solution A;
	cout << A.isMatch(my,my2);
	return 0;
}