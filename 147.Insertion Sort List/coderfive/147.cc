class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
	ListNode rh(0), *p = &rh, *prev, *p_last, *cur;
	rh.next = head;
	if (!head) return head;
	p = head->next;
	p_last = head;
	while (p) {
	    prev = &rh;
	    cur = prev->next;
	    while (cur != p && cur->val < p->val) {
		cur = cur->next;
		prev = prev->next;
	    }
	    if (cur == p) {
		p_last = p;
		p = p->next;
	    }
	    else {
		p_last->next = p->next;
		p->next = cur;
		prev->next = p;
		p = p_last->next;
	    }
	}
	return rh.next;
    }
};
