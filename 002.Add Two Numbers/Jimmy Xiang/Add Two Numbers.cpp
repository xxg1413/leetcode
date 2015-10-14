#include <iostream>
#include <vector>

using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

     ListNode head(-1);
     ListNode * node = &head;


     int add = 0;

     for(ListNode *p1 = l1,*p2 = l2;  
     	 p1 != nullptr || p2 != nullptr; 
     	 p1=(p1==nullptr? nullptr: p1->next), p2=(p2==nullptr? nullptr:p2->next), node = node->next )  {

     	 	const int v1 = (p1 == nullptr? 0: p1->val);
     	 	const int v2 = (p2 == nullptr? 0: p2->val);

     	 	const int value = (v1 + v2  + add ) % 10;
     	 	add = (v1 + v2 + add) / 10;
     	 	
     	 	node->next = new ListNode(value);
     	}

     	 	if( add > 0) 
     	 		node->next = new ListNode(add);

     	 	return head.next;
     }
};


ListNode* init_list(vector<int> &list, ListNode *head)
{
	ListNode *tmp = nullptr;

	for(auto i: list) {
		ListNode *node = new ListNode(i);

		if(head == nullptr) {
			head = tmp = node;

		} else {
		     tmp->next = node;
		     tmp = tmp->next;
		}
	}

	return head;

}

int print_list(ListNode *head)
{
	if(head == nullptr) {
		return -1;
	}

	ListNode *p = head;

	while( p ) {

		cout<<p->val<<" "; 
		p = p->next;
		
	}

	cout<<endl;

	return 0;
}

int main()
{

	vector<int> test1 = {1,3,4,5,8};
	vector<int> test2 = {2,5,8,9};

	ListNode *head1 = nullptr;
	ListNode *head2 = nullptr;

	head1 = init_list(test1, head1);
	head2 = init_list(test2, head2);

	Solution s;
	ListNode * head3 = s.addTwoNumbers(head1, head2);


	print_list(head1);
	print_list(head2);

	print_list(head3);

	return 0;

}