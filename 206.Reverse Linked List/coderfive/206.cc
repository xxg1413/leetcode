class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev, *cur, *tmp;
        prev = head;
        if (!head) return head;
        cur = prev->next;
        prev->next = NULL;
        while (cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};
