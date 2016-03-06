class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
	int n = 0;
	ListNode* p = head;
	while (head) {
	    n++;
	    head = head->next;
	}
	return toBST(&p, n);
    }
    TreeNode* toBST (ListNode** head, int n) {
	int left_size = n/2;
	if (n == 0) return NULL;
	TreeNode* left = toBST(head, left_size);
	TreeNode* res = new TreeNode((*head)->val);
	*head = (*head)->next;
	res->left = left;
	res->right = toBST(head, n-left_size-1);

	return res;
    }
};
