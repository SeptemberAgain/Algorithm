#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;
class Solution {
public:
	int theLastOne(int n,int m, int k)
	{
		
		int nums[1000];
		int *p = nums;
		for ( int i = 0;i<n;i++) *(p+i)=i+1;
		int out = 0;
		int curCall = 0;
		int curNum = m;
		while (out < n-1)
		{
			if (*(p+curNum-1)!=0) curCall++;
			if (curCall==k)
			{
				*(p+curNum-1)=0;
				curCall = 0;
				out++;
			}
			curNum++;
			if (curNum >n) curNum = 1;
		}
		while(*p==0)p++;
		return *p;
	}
};


int main()
{
	Solution A;
	int n,m,k;
	cout<<"输入总人数:  ";
	cin>>n;
	cout<<"输入开始编号:  ";
	cin>>m;
	cout<<"输入报数间隔:  ";
	cin>>k;
	cout<<A.theLastOne(n,m,k)<<endl;
	return 0;
}