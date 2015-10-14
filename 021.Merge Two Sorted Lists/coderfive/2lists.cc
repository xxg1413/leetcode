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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode ln(0), *pln = &ln;

            while (l1 && l2) {
                if (l1->val < l2->val) {
                    pln->next = l1;
                    l1 = l1->next;
                }
                else {
                    pln->next = l2;
                    l2 = l2->next;
                }
                pln = pln->next;
            }

            if (l1) pln->next = l1;
            else if (l2) pln->next = l2;

            return ln.next;
        }
};

/*
 * input: ListNode*{2} ## ListNode*
 *        ListNode*: {}
 *                  | {int [, int]*}
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
    int err = 0;
    string buf;
    ListNode ln(0), *pln1, *pln2, *ret, *res;
    ListNode *expected, *ret2, *saved_pln1, *saved_pln2;

    while (true) {
        cin >> &ln;
        if (cin.eof()) break;
        pln1 = ln.next;

        cin >> &ln;
        pln2 = ln.next;
        cin >> buf >> &ln;
        res = ln.next;
        saved_pln1 = dup_list(pln1);
        saved_pln2 = dup_list(pln2);

        ret = Solution().mergeTwoLists(pln1, pln2);
        
        ret2 = ret;
        expected = res;

        while (ret && res && ret->val == res->val) {
            res = res->next;
            ret = ret->next;
        }
        if (ret || res) {
            err = 1;
            cout << "input: " << saved_pln1 << " " << saved_pln2 << endl
                 << "ret: " << ret2 << endl
                 << "expected: " << expected << endl << endl;
        }
        free_list (saved_pln1);
        free_list (saved_pln2);
        free_list (ret2);
        free_list (expected);
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
