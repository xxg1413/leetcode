class Solution {
public:
    ListNode* sortList(ListNode* head) {
	int len = 1, i;
	ListNode rh(0), *p, *p2, *cur = head, *cur_head = &rh, *second, *left;
	rh.next = head;
	while (true) {
	    cur_head = &rh;
	    while (true) {
		i = 0;
		second = cur_head;
		while (i < len && second) {
		    i++;
		    second = second->next;
		}
		if (!second) break;
		p = second;
		second = second->next;
		p->next = NULL;
		p = second;
		i = 1;
		while (i < len && p) {
		    i++;
		    p = p->next;
		}
		left = NULL;
		if (p) {
		    left = p->next;
		    p->next = NULL;
		}
		while (cur_head->next && second) {
		    while (cur_head->next && cur_head->next->val < second->val) {
			cur_head = cur_head->next;
		    }
		    if (cur_head->next) {
			p = cur_head->next;
			cur_head->next = second;
			p2 = second->next;
			second->next = p;
			cur_head = second;
			second = p2;
		    }
		    else {
			cur_head->next = second;
			second = NULL;
		    }
		}
		while (cur_head->next) {
		    cur_head = cur_head->next;
		}
		cur_head->next = left;
	    }
	    len <<= 1;
	    if (cur_head == &rh) break;
	}
	return rh.next;
    }
};
