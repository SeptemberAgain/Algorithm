#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <unordered_map>
//Add Two Numbers
using namespace std;


struct ListNode 
{     
	int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* my_list = new ListNode(-1);
		ListNode* final_list = my_list;
		int carry = 0;
		int res;
		while (l1 || l2)
		{
			res = l1 ? l1->val:0 + l2 ? l2->val:0 + carry;
			carry = res % 10;
			res = res / 10;
			my_list->next = new ListNode(res);
			my_list = my_list->next;
			if (l1) l1->next;
			if (l2) l2->next;
		}
		if (carry) my_list->next = new ListNode(1);
		return final_list->next;
	}
};