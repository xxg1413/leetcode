/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
{
	if (NULL == head || NULL == head->next) return head;
	struct ListNode *tmp = swapPairs(head->next->next);
	struct ListNode *ret = head->next;
	head->next = tmp;
	ret->next = head;
	return ret;
}
