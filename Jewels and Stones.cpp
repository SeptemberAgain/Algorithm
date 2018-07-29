#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <unordered_set>
//Jewels and Stones
using namespace std;


class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int result = 0;
		unordered_set<char> s;
		for (char c : J) 
			s.insert(c);
		for (char c : S) 
		{
			if (s.count(c)) ++result;
		}
		return result;
	}
};

int main()
{
	Solution A;
	string J;
	string S;
	cin >> J >> S;
	cout << A.numJewelsInStones(J, S);
	return 0;
}