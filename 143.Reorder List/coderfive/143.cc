class Solution {
public:
    void reorderList(ListNode* head) {
	ListNode* slow = head, *fast = head;
	if (!head) return;

	while (fast && fast->next) {
	    slow = slow->next;
	    fast = fast->next->next;
	}
	ListNode* last = NULL, *cur = slow->next, *tmp;
	slow->next = NULL;
	while (cur) {
	    tmp = cur->next;
	    cur->next = last;
	    last = cur;
	    cur = tmp;
	}
	while (last) {
	    tmp = head->next;
	    head->next = last;
	    head = tmp;

	    tmp = last->next;
	    last->next = head;
	    last = tmp;
	}
    }
};
