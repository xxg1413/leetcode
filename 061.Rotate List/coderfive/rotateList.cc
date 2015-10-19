#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode *pln, *last;
            int size = 0;
            if (!head) return head;
            pln = head;
            while (pln) {
                size++;
                last = pln;
                pln = pln->next;
            }
            k %= size;
            k = size-k;
            if (k == 0 || head == NULL) return head;
            pln = head;
            while (--k != 0)
                pln = pln->next;

            last->next = head;
            last = pln->next;
            pln->next = NULL;

            return last;
        }
};

/*
 * input: ListNode* int ## ListNode*
 */

ostream& operator<<(ostream& out, ListNode* pl) {
    if (!pl) {
        out << "{}";
        return out;
    }
    out << "{" << pl->val;
    pl = pl->next;
    while (pl) {
        out << ", " << pl->val;
        pl = pl->next;
    }
    out << "}";
    return out;
}

istream& operator >> (istream& is, ListNode* pl) {
    int val;
    int c;
    pl->next = NULL;
    while (!cin.eof() && isspace(cin.peek())) cin.get();
    if (cin.eof()) return is;

    if (cin.peek() == '{') cin.get();
    else return is;

    while (isspace(cin.peek())) cin.get();
    if (cin.peek() == '}') {
        cin.get();
        return is;
    }

    while (true) {
        cin >> val;
        pl->next = new ListNode(val);
        pl = pl->next;
        while (isspace(c = cin.get()));
        if (c == '}') return is;
    }
    return is;
}

void free_list (ListNode *pln) {
    ListNode *next;
    while (pln) {
        next = pln->next;
        delete pln;
        pln = next;
    }
}

ListNode* dup_list (ListNode *pln) {
    ListNode ln(0), *p = &ln;
    while (pln) {
        p->next = new ListNode(pln->val);
        pln = pln->next;
        p = p->next;
    }
    return ln.next;
}

int main() {
    int err = 0, k;
    string buf;
    ListNode pn(0), *saved_pn, *ret, expected(0), *res, *ret2;

    while (true) {
        cin >> &pn;
        if (cin.eof()) break;
        cin >> k >> buf >> &expected;
        saved_pn = dup_list (pn.next);
        ret = Solution().rotateRight(pn.next, k);
        ret2 = ret;
        res = expected.next;

        while (ret && res && ret->val == res->val) {
            res = res->next;
            ret = ret->next;
        }
        if (ret || res) {
            err = 1;
            cout << "input: " << saved_pn << "  " << k << endl
                 << "ret: " << ret2 << endl
                 << "expected: " << expected.next << endl << endl;
        }

        free_list (saved_pn);
        free_list (expected.next);
        free_list (ret2);
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
