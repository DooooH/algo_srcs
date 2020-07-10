/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

	void deleteNode(ListNode *erase, ListNode *pre_node){
		pre_node->next = erase->next;
		delete erase;
	}

    ListNode* deleteDuplicates(ListNode *head) {
        ListNode *temp = head;
        ListNode *pre_node = head;

		while (temp != nullptr)
		{

			if (temp->next != nullptr && temp->val == temp->next->val)
			{
				while (temp->next != nullptr && temp->val == temp->next->val)
				{
					deleteNode(temp->next, temp);
				}
				if (temp == head)
				{
					head = temp->next;
					delete temp;
					temp = head;
				}
				else
				{
					deleteNode(temp, pre_node);
					temp = pre_node->next;
				}
			}
			else
			{
				pre_node = temp;
				temp = temp->next;
			}
		}
		return head;
    }
};