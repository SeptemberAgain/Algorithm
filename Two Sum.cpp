#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <unordered_map>
//Two Sum
using namespace std;


class Solution 
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int,int> s;
		for (int i = 0;i < nums.max_size();i++)
		{
			if (s.count(target - nums[i]))
			{
				return{i,s[target - nums[i]]};
			}
			s[nums[i]]=i;
		}
		return {};
	}
};

int main()
{
	Solution A;
	int num;
	vector<int> mynums;
	int target;
	while (cin>>num)
	{
		if (cin.get() == '\n')
			break;
		mynums.push_back(num);
	}
	cin >> target;
	cout << A.twoSum(mynums, target)[0] << A.twoSum(mynums, target)[1];
	return 0;
}