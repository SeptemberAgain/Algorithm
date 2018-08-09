#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
//ZigZag Conversion
using namespace std;


class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1)
			return s;
		string result = "";
		int cycle = 2 * numRows - 2;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = i;j < s.length();j += cycle)
			{
				result += s[j];
				int temp = (j - i) + cycle - i;
				if (temp < s.length() && (i != 0) && (i != (numRows - 1)))
					result += s[temp];
			}
		}
		return result;
	}
};

int main()
{
	Solution A;
	string my_str;
	getline(cin, my_str);
	int num;
	cin >> num;
	cout << A.convert(my_str, num) << endl;
	return 0;
}