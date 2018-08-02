#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
//Longest Palindromic Substring
using namespace std;

char str[1001];
char doubled_str[2003];
int p[2003];

int Init(char* my_string)
{
	int length = strlen(my_string);
	doubled_str[0] = '$';
	doubled_str[1] = '#';
	int j = 2;
	for (int i = 0; i < length; i++)
	{
		doubled_str[j++] = my_string[i];
		doubled_str[j++] = '#';
	}
	doubled_str[j] = '\0';
	return j;
}

class Solution {
public:
	string longestPalindrome(string s)
	{
		if (s.size() == 0) return "\0";
		char* str = (char *)s.data();
		int str_length = Init(str);
		int max_Length = -1;
		int id = 0;
		int right = 0;
		int temp;
		for (int i = 1;i < str_length;i++)
		{
			if (i < right) p[i] = min(p[2 * id - i], right - i);
			else p[i] = 1;
			while (doubled_str[i - p[i]] == doubled_str[i + p[i]]) p[i]++;
			if (right < i + p[i])
			{
				id = i;
				right = i + p[i];
			}
			if (max_Length <= p[i] - 1) temp = i / 2;
			max_Length = max(max_Length, p[i] - 1);
		}
		return s.substr(temp - (max_Length - 1) / 2 - 1, max_Length);
	}
};

int main()
{
	Solution A;
	string my_str;
	getline(cin, my_str);
	cout << A.longestPalindrome(my_str) << endl;
	return 0;
}