// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
// 	int find_idx(vector<int> &accu, int val, int idx)
// 	{
// 		for (int i = 0; i < idx; i++)
// 		{
// 			if (accu[i] == val)
// 			{
// 				return i;
// 			}
// 		}
// 		return -1;
// 	}

// 	vector<int> makeArray(ListNode* head)
// 	{
// 		vector<int> accu;
// 		ListNode* ptr = head;
// 		int sum = 0;

// 		while (ptr != nullptr)
// 		{
// 			sum += ptr->val;
// 			accu.push_back(sum);
// 			ptr = ptr->next;
// 		}

// 		return accu;
// 	}

//     ListNode* removeZeroSumSublists(ListNode* head) {
// 		// vector<int>::iterator it;
// 		ListNode *dummy = new ListNode(0, head);
// 		ListNode *temp;
// 		ListNode *temp2;
		
// 		int i;

// 		if (head == nullptr)
// 		{
// 			return head;
// 		}
		
// 		for (int j = 0; j <= 3; j++)
// 		{
// 			temp = dummy->next;
// 			dummy->next = head->next;
// 			head = dummy->next;
// 			delete temp;
// 		}

// 		// while (1)
// 		// {
// 		// 	vector<int> accu = makeArray(head); // 여러번 만들어야 할 수도

// 		// 	for (i = 0; i < accu.size(); i++)
// 		// 	{
// 		// 		if (accu[i] == 0)
// 		// 		{
// 		// 			for (int j = 0; j <= i; j++)
// 		// 			{
// 		// 				temp = head;
// 		// 				head = head->next;
// 		// 				delete temp;
// 		// 			}
// 		// 			break ;
// 		// 		}
// 		// 		else if (find_idx(accu, accu[i], i) != -1)
// 		// 		{
// 		// 			int start = find_idx(accu, accu[i], i) + 1;
// 		// 			ListNode *ptr2 = head;

// 		// 			for (int j = 0; j < start; j++)
// 		// 			{
// 		// 				ptr2 = ptr2->next;
// 		// 			}
// 		// 			for (int j = start; j < i; j++)
// 		// 			{
// 		// 				temp2 = ptr2->next;
// 		// 				delete ptr2;
// 		// 				ptr2 = temp2;
// 		// 			}
// 		// 			break ;
// 		// 		}
// 		// 	}
// 		// 	if (i == accu.size())
// 		// 		break ;
// 		// }
// 		return head;
//     }
// };