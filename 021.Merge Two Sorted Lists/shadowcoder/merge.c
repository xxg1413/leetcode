/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *tail = NULL, *head = NULL; 
	if (NULL == l1 || NULL == l2) {
		return l2? l2 : l1;
	}
	if (l1->val <= l2->val) {
		head = tail = l1;
		l1 = l1->next;
	} else {
		head = tail = l2;
		l2 = l2->next;
	}
	tail->next = NULL;
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		} else {
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
		tail->next = NULL;
	}
	tail->next = l1? l1:l2;
	return head;
}
