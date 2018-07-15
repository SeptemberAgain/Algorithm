//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <cstdio>
//#include <cmath>
////Tree Recovery
//
//using namespace std;
//string str_pre;
//string str_mid;
//string str_post;
//
//void get_str_post(string s1, string s2)
//{
//	if (s1 == "" || s2 == "")
//		return;
//	int	root_pos = s2.find(s1[0]);
//	get_str_post(s1.substr(1, root_pos+1), s2.substr(0, root_pos));
//	get_str_post(s1.substr(root_pos + 1), s2.substr(root_pos + 1));
//	str_post += s1[0];
//}
//
//
//int main()
//{
//	char ch[26];
//	cin >> ch;
//	str_pre = ch;
//	cin >> ch;
//	str_mid = ch;
//	get_str_post(str_pre, str_mid);
//	cout << str_post << endl;
//	return 0;
//}
//
//
