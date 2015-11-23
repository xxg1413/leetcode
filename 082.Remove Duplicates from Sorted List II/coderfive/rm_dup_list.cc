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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode rhead(0), *hd, *ha, *hb;
        rhead.next = head;
        hd = &rhead;
        while (true) {
            ha = hd->next;
            if (ha) hb = ha->next;
            if (!ha || !hb) break;
            if (ha->val != hb->val)
                hd = ha;
            else {
                while (hb && ha->val == hb->val) hb = hb->next;
                hd->next = hb;
            }
        }
        return rhead.next;
    }
};

/*
 * input: ListNode ## ListNode
 */

template<typename T>
istream& operator >> (istream& in, vector<T>& vi) {
    T val;
    vi.clear();
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
        vi.push_back(val);
    }

    return in;
}

template<typename T>
ostream& operator << (ostream& out, vector<T>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << vi[0];
    for (int i = 1; i < vi.size(); i++)
        out << ", " << vi[i];
    out << "}";
    return out;
}

istream& operator >> (istream& in, ListNode& ln) {
    vector<int> v;
    in >> v;
    ln.next = NULL;
    ListNode *pln = &ln;
    for (auto n : v) {
        pln->next = new ListNode(n);
        pln = pln->next;
    }
    return in;
}

ostream& operator << (ostream& out, ListNode* ln) {
    ListNode *pln = ln;
    out << "{";
    if (pln) {
        out << pln->val;
        pln = pln->next;
    }
    while (pln) {
        out << ", " << pln->val;
        pln = pln->next;
    }
    out << "}";

    return out;
}

int main() {
    bool err = false;
    string buf;
    ListNode na(0), nb(0), *res;
    vector<int> v;

    while (true) {
        cin >> na;
        if (cin.eof()) break;
        v.clear();
        ListNode *pln = na.next;
        while (pln) {
            v.push_back(pln->val);
            pln = pln->next;
        }
        cin >> buf >> nb;
        res = Solution().deleteDuplicates(na.next);
        ListNode *n1 = res, *n2 = nb.next;
        while (n1 && n2 && n1->val == n2->val) {
            n1 = n1->next;
            n2 = n2->next;
        }
        if (n1 || n2) {
            err = true;
            cout << "input: " << v << endl
                 << "result: " << res << endl
                 << "expected: " << nb.next << endl << endl;
        }
    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
