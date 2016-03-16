class Solution {
    public:
	RandomListNode* copyRandomList (RandomListNode* head) {
	    unordered_map<RandomListNode*, RandomListNode*> mp;
	    if (!head) return head;
	    RandomListNode rh(1), *prh = &rh, *oh = head;
	    int sz = 0;
	    while (oh) {
		sz++;
		oh = oh->next;
	    }
	    oh = head;
	    RandomListNode* p = (RandomListNode*)operator new (sizeof (RandomListNode) * sz);
	    while (oh) {
		prh->next = new (p++) RandomListNode(oh->label);
		prh = prh->next;
		mp[oh] = prh;
		oh = oh->next;
	    }
	    prh = rh.next;
	    oh = head;
	    while (prh) {
		if (oh->random) prh->random = mp[oh->random];
		prh = prh->next;
		oh = oh->next;
	    }

	    return rh.next;
	}
};
