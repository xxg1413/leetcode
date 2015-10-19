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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode ln(0), *pln = &ln;
            ln.next = head;
            int len = 0;
            while (head) {
                len++;
                head = head->next;
            }

            while (len-- != n) {
                pln = pln->next;
            }

            pln->next = pln->next->next;
            return ln.next;
        }
};

/*
 * input: ListNode* int ## ListNode*
 * ListNode* : {}
 *            | {int [, int]*}
 */

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

ostream& operator<<(ostream& out, ListNode* pl) {
    out << "{";
    if (pl)
        out << pl->val;
    pl = pl->next;
    while (pl) {
        out << ", " << pl->val;
        pl = pl->next;
    }
    out << "}";
    return out;
}

void free_list (ListNode *pln) {
    ListNode *next;
    while (pln) {
        next = pln->next;
        delete pln;
        pln = next;
    }
}


int main() {
    int err = 0, n;
    string buf;
    ListNode ln(0), *pln1, *ret, *res, *expected, *ret2;

    while (true) {
        cin >> &ln;
        if (cin.eof()) break;
        pln1 = ln.next;
        cin >> n >> buf >> &ln;
        res = expected = ln.next;

        ret = ret2 = Solution() . removeNthFromEnd (pln1, n);

        while (ret && res && ret->val == res->val) {
            ret = ret->next;
            res = res->next;
        }
        if (ret || res) {
            err = 1;
            cout << "input: " << pln1 << " " << n << endl
                 << "ret: " << ret2 << endl
                 << "expected: " << expected << endl << endl;
        }
        free_list (ret2);
        free_list (expected);
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
