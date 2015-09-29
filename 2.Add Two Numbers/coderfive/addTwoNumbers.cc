#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0, val, v1, v2;
            ListNode r2(1), *res = &r2;
            while (l1 || l2) {
                val = 0;
                if (l1) {
                    val += l1->val;
                    l1 = l1->next;
                }
                if (l2) {
                    val += l2->val;
                    l2 = l2->next;
                }
                res->next = new ListNode((val+carry) % 10);
                if (val + carry >= 10)
                    carry = 1;
                else
                    carry = 0;
                res = res->next;
            }

            if (carry)
                res->next = new ListNode (1);

            return r2.next;
        }
};

/*
 * input: [num int{num}]{2}  ## notes to be ignored
 */

void print_list (ListNode* lt) {
    while (lt) {
        cout << lt->val << ' ';
        lt = lt->next;
    }
    cout << endl;
}

void free_list (ListNode* lt) {
    ListNode *next;
    while (lt) {
        next = lt->next;
        delete lt;
        lt = next;
    }
}

void get_list (ListNode* lt) {
    int n, val;
    cin >> n;
    if (cin.eof()) return;
    while (n--) {
        cin >> val;
        lt->next = new ListNode (val);
        lt = lt->next;
    }
}

int main() {
    ListNode tag_l1(1), tag_l2(1), *res, *l1, *l2;
    string buf;
    l1 = &tag_l1;
    l2 = &tag_l2;

    while (true) {
        tag_l1.next = NULL;
        get_list (&tag_l1);
        if (tag_l1.next == NULL) return 0;
        get_list (&tag_l2);
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

        res = Solution() . addTwoNumbers (tag_l1.next, tag_l2.next);
        print_list (res);
        free_list (res);
        free_list (tag_l1.next);
        free_list (tag_l2.next);
    }

    return 0;
}
