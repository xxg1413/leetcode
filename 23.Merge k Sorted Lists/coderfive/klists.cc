#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    struct list_wrapper {
        ListNode *pl;
        bool operator < (const list_wrapper &rhs) const {
            return this->pl->val > rhs.pl->val;
        }
        list_wrapper (ListNode* ln) {
            pl = ln;
        }
        list_wrapper () {}
    };
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode ln(0), *pln = &ln, *tp;
            pln->next = NULL;
            priority_queue<list_wrapper> pq;
            for (auto a : lists)
                if (a)
                    pq.push(list_wrapper(a));
            while (!pq.empty()) {
                pln->next = new ListNode(pq.top().pl->val);
                pln = pln->next;
                tp = pq.top().pl;
                pq.pop();
                if (tp->next)
                    pq.push(list_wrapper(tp->next));
            }

            return ln.next;
        }
};

/*
 * input: vector<ListNode*> ## ListNode*
 *        vector<T>: {}
 *                  | {T [, T]*}
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

istream& operator >> (istream& is, vector<ListNode*>& v) {
    ListNode ln(0);
    int c;
    v.clear();
    while (!cin.eof() && isspace(cin.peek())) cin.get();
    if (cin.eof()) return is;

    if (cin.peek() == '{') cin.get();
    else return is;

    while (true) {
        cin >> &ln;
        v.push_back(ln.next);
        while (isspace(c = cin.get()));
        if (c == '}') return is;
    }
    return is;
}

template<typename T> 
ostream& operator<<(ostream& out, vector<T>& v) {
    if (v.size() == 0) {
        out << "{}";
        return out;
    }
    out << "{" << v[0];
    for (typename::vector<T>::size_type i = 1; i < v.size(); i++)
        out << ", " << v[i];
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
    int err = 0;
    ListNode ln(0), *pln, *res, *ret, *expected, *ret2;
    vector<ListNode*> vp;
    string buf;

    while (true) {
        cin >> vp;
        if (cin.eof()) break;
        cin >> buf >> &ln;
        res = ln.next;

        ret = Solution() . mergeKLists(vp);
        expected = res;
        ret2 = ret;

        while (res && ret && res->val == ret->val) {
            res = res->next;
            ret = ret->next;
        }

        if (res || ret) {
            err = 1;
            cout << "input: " << vp << endl
                 << "ret: " << ret2 << endl
                 << "expected: " << expected << endl << endl;
        }
        free_list(ret2);
        free_list(expected);
        for (auto a : vp)
            free_list(a);
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
