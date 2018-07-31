#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
//Longest Substring Without Repeating Characters
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> hash(256, -1);
		int start = -1, length = 0;
		for (int i = 0;i < s.size();i++)
		{
			start = max(start, hash[s[i]]);
			hash[s[i]] = i;
			length = max(length, i - start);
		}
		return length;
	}
};

int main()
{
	Solution A;
	string my_str;
	getline(cin, my_str);
	cout << A.lengthOfLongestSubstring(my_str) << endl;
	return 0;
}