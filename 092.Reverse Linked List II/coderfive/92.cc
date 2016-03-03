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
	ListNode() : next(NULL){}
	ListNode(const initializer_list<int>& ilist) {
		ListNode** node = &next;
		next = NULL;
		// leaks memory here
		for (auto it = ilist.begin(); it != ilist.end(); it++) {
			*node = new ListNode(*it);
			node = &((*node)->next);
		}
	}
	ListNode(const vector<int>& ilist) {
		ListNode** node = &next;
		next = NULL;
		// leaks memory here
		for (auto it = ilist.begin(); it != ilist.end(); it++) {
			*node = new ListNode(*it);
			node = &((*node)->next);
		}
	}
	bool operator== (const ListNode& rhs) {
		ListNode* p = next, *p2 = rhs.next;
		while (p && p2 && p->val == p2->val) {
			p = p->next;
			p2 = p2->next;
		}
		if (p || p2) return false;
		return true;
	}
	bool operator!= (const ListNode& rhs) {
		return !(*this == rhs);
	}
};


ostream& operator<< (ostream& out, const ListNode& node) {
	ListNode* p = node.next;
	out << "{";
	if (p) {
		out << " " << p->val;
		p = p->next;
	}
	while (p) {
		out << ", " << p->val;
		p = p->next;
	}
	out << "}";
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
	    ListNode rh(0), *p, *tmp, *pm, *pn;
	    rh.next = head;
	    p = &rh;
	    int i = 1;
	    while (i < m) {
		    p = p->next;
		    i++;
	    }
	    ListNode* start = p, *s2 = p->next;
	    p = p->next;
	    pm = p;
	    p = p->next;
	    i++;
	    while (i <= n) {
		    tmp = p->next;
		    p->next = pm;
		    pm = p;
		    p = tmp;
		    i++;
	    }
	    start->next = pm;
	    s2->next = p;
	    return rh.next;
    }
};

bool err = false;
void do_test (const vector<int>& v, const int m, const int n, const ListNode& res) {
	static int counter = 1;
	ListNode ret_head, node(v), saved_node(v);
	ret_head.next = Solution().reverseBetween(node.next, m, n);
	if (ret_head != res) {
		cout << "#" << counter << "\n";
		cout << "input: " << saved_node << ", " << m << ", " << n << "\n"
		     << "expected: " << res << "\n"
		     << "got: " << ret_head << "\n\n";
		err = true;
	}
}

int main() {
	do_test ({1,2,3}, 2,2, {1,2,3});
	do_test ({1,2,3}, 2,3, {1,3,2});
	do_test ({1,2,3}, 1,2, {2,1,3});
	do_test ({1,2,3}, 1,3, {3,2,1});
	do_test ({1,2,3}, 1,1, {1,2,3});
	do_test ({1,2,3}, 3,3, {1,2,3});
	do_test ({1,2}, 1,2, {2,1});
	do_test ({1}, 1,1, {1});


	if (!err)
		cout << "All tests passed!\n";

	return 0;
}
