#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
//Tree Recovery

using namespace std;
string str_pre;
string str_mid;
string str_post;

void get_str_pre(string s2, string s3)
{
	if (s2 == "" || s3 == "")
		return;
	str_pre += s3[s3.size()-1];
	int	root_pos = s2.find(s3[s3.size() - 1]);
	get_str_pre(s2.substr(0, root_pos), s3.substr(0, root_pos));
	get_str_pre(s2.substr(root_pos + 1), s3.substr(root_pos,s3.size()-root_pos-1));
}

int main()
{
	char ch[26];
	cin >> ch;
	str_mid = ch;
	cin >> ch;
	str_post = ch;
	get_str_pre(str_mid, str_post);
	cout << str_pre << endl;
	return 0;
}


