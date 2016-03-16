class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
	ListNode* fast = head, *slow = head;
	while (fast && fast->next) {
	    fast = fast->next->next;
	    slow = slow->next;
	    if (fast == slow) {
		while (head != fast) {
		    head = head->next;
		    fast = fast->next;
		}
		return head;
	    }
	}
	return NULL;
    }
};
