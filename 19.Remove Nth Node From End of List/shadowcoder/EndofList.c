struct node {
	struct ListNode* past;
	struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int num) 
{
	struct ListNode* bak = head;
	struct node n[8192] = {0};
	int k = 0;
	struct ListNode* past = NULL;
	while (head) {
		n[k].past = past;
		n[k++].next = head->next;
		past = head;	
		head = head->next;
	}
	if (!n[k - num].past) return bak->next;
	n[k - num].past->next = n[k - num].next;
	return bak;
}
