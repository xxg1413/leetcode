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
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode ln(0), *p1, *p2, *p3, *p4;
            p1 = &ln;
            ln.next = head;

            if (k < 2) return head;
            int i;
            while (true) {
                i = 0;
                p2 = p1->next;
                while (i < k && p2) {
                    p2 = p2->next;
                    i++;
                }
                if (i < k) break;
                i = 1;
                p2 = p1->next;
                p3 = p2->next;
                while (i++ < k) {
                    p4 = p3->next;
                    p3->next = p2;
                    p2 = p3;
                    p3 = p4;
                }
                p1->next->next = p3;
                p4 = p1->next;
                p1->next = p2;
                p1 = p4;
            }

            return ln.next;
        }
};

/*
 * input: ListNode int ##  ListNode
 * ListNode: {}
 *           | {int [, int]*}
 */

void free_list (ListNode* pn) {
    ListNode* next;
    while (pn) {
        next = pn->next;
        delete pn;
        pn = next;
    }
}

ListNode* dup_list (ListNode* pn) {
    ListNode ln(0), *p2 = &ln;
    while (pn) {
        p2->next = new ListNode(pn->val);
        p2 = p2->next;
        pn = pn->next;
    }
    return ln.next;
}

istream& operator >> (istream& in, ListNode& ln) {
    ln.next = NULL;
    ListNode *pn = &ln;
    int val;
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;
    in.get();

    while (true) {
        while (isspace(in.peek())) in.get();
        if (in.peek() == '}') {
            in.get();
            return in;
        }
        else if (in.peek() == ',') in.get();
        in >> val;
        pn->next = new ListNode(val);
        pn = pn->next;
    }

    return in;
}

ostream& operator << (ostream& out, ListNode& ln) {
    ListNode* pn = ln.next;
    out << "{";
    if (pn) {
        out << pn->val;
        pn = pn->next;
    }
    while (pn)
        out << ", " << pn->val;
    out << "}";

    return out;
}

int main() {
    int err = 0, n;
    string buf;
    ListNode ln(0), *expected, *ret, *expected2, *ret2, *pn, *pn2;

    while (true) {
        cin >> ln;
        if (cin.eof()) break;
        pn = ln.next;
        pn2 = dup_list(pn);

        cin >> n >> buf >> ln;
        ret = ret2 = Solution().reverseKGroup(pn, n);
        expected = expected2 = ln.next;

        while (expected && ret && expected->val == ret->val) {
            expected = expected->next;
            ret = ret->next;
        }
        if (expected || ret) {
            err = 1;
            cout << "input: " << pn2 << n << endl
                 << "ret: " << ret2 << endl
                 << "expected: " << expected2 << endl << endl;
        }
        free_list (pn2);
        free_list (ret2);
        free_list (expected2);
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
