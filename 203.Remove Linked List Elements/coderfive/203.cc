class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode rh(0);
        rh.next = head;
        head = &rh;
        while (head->next) {
            if (head->next->val == val)
                head->next = head->next->next;
            else
                head = head->next;
        }

        return rh.next;
    }
};
