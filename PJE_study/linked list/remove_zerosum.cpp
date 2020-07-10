#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		if (head == NULL)
			return head;
		unordered_map<int, ListNode*> um;
		int presum = 0;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		um[0] = dummy;
		while (head != NULL)
		{
			presum+=head->val;
			if (um.find(presum) != um.end())
			{
				ListNode *prev = um[presum];
				int sum = presum;
				while(prev != NULL && prev != head)
				{
					prev = prev->next;
					sum += prev->val;
					if (prev!=head)
						um.erase(sum);
				}
				um[presum]->next = head->next;
			}
			else
			{
				um[presum] = head;
			}
			head = head->next;
		}
		return dummy->next;
	}
}