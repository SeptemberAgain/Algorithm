#include <iostream>
#include <map>
#include <string>
//Let the Balloon Rise

using namespace std;

int main()
{
	int n;
	while (cin>>n && n)
	{
		map<string,int>ballon;
		string s;
		for(int i = 0;i<n;i++)
		{
			cin>>s;
			ballon[s]++;
		}
		int max_num = 0;
		map<string,int>::iterator point ,loc;
		for(point = ballon.begin();point!=ballon.end();point++)
		{
			if (max_num < (point ->second))
			{
				max_num = point ->second;
				loc = point;
			}
		}
		cout << loc->first<<endl;
	}
	return 0;
}



