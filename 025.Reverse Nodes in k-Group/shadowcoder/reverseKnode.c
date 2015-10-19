/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
	int i;
	struct ListNode *this = head, *o;
	for (i = 1; i < k && head; i++) 
		head = head->next;
	if (!head) return this;
	
	for(head = this, i = 1; i < k; i ++) {
		o = head->next;
		head->next = o->next;
		o->next = this;
		this = o;
	}
	
	head->next = reverseKGroup(head->next, k);
	return this;
}
