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
		ListNode* partition(ListNode* head, int x) {
			ListNode rh(0), *p = &rh, *p2, *tmp;
			rh.next = head;
			while (p->next && p->next->val < x)
				p = p->next;
			p2 = p;
			while (p2->next) {
				tmp = p2->next;
				if (tmp->val < x && p2 != p) {
					p2->next = tmp->next;
					tmp->next = p->next;
					p->next = tmp;
					p = p->next;
				}
				else
					p2 = p2->next;
			}
			return rh.next;
		}
};

bool err = false;
void do_test (const ListNode& node, const int x, const ListNode& res) {
	static int counter = 1;
	ListNode ret_head;
	ret_head.next = Solution().partition(node.next, x);
	if (ret_head != res) {
		cout << "#" << counter << "\n";
		cout << "input: " << node << ", " << x << "\n"
		     << "expected: " << res << "\n"
		     << "got: " << ret_head << "\n\n";
		err = true;
	}
}

int main() {
	do_test ({}, 3, {});
	do_test ({1,4,3,2,5,2}, 3, {1,2,2,4,3,5});
	do_test ({1}, 3, {1});
	do_test ({4}, 3, {4});
	do_test ({3,2,1}, 2, {1,3,2});
	do_test ({3,1,2}, 3, {1,2,3});

	if (!err)
		cout << "All tests passed!\n";

	return 0;
}
