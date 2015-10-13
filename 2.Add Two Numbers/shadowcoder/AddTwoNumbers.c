/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	int jin = 0;
	struct ListNode* ll = l1;
	struct ListNode* lr = l2;
	while (l1) {
		l1->val += jin;
		jin = 0;
		if (l2) {
			l1->val += l2->val;
			l2 = l2->next;
		}
		if (l1->val > 9) {
			jin = 1;
			l1->val -= 10;
		}

		if (!l1->next) {
			if (!l2) {
				if (jin) {
					lr->val = jin;
					l1->next = lr;
					lr->next = NULL;
					l1 = lr;
				}
			} else {
				l1->next = l2;
				l2 = NULL;
			}
		}
		l1 = l1->next;
	}

	return ll;
}
