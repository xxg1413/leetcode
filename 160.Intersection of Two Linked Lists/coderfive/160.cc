class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *ha = headA, *hb = headB;
	ListNode *long_list, *short_list, *rem;
	while (ha && hb && ha != hb) {
	    ha = ha->next;
	    hb = hb->next;
	}
	if (ha == hb && ha) return ha;
	if (ha) {
	    long_list = headA;
	    short_list = headB;
	    rem = ha;
	}
	else {
	    long_list = headB;
	    short_list = headA;
	    rem = hb;
	}
	while (rem) {
	    rem = rem->next;
	    long_list = long_list->next;
	}
	while (long_list && long_list != short_list) {
	    long_list = long_list->next;
	    short_list = short_list->next;
	}
	return long_list;
    }
};
