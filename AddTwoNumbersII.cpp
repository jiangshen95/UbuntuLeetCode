#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode *p;
        p = l1;
        while(p) {
        	len1++;
        	p = p->next;
		}
		
		p = l2;
		while(p) {
			len2++;
			p = p->next;
		}
		
		if(len2 > len1) {
			ListNode *t = l1;
			l1 = l2;
			l2 = t;
			swap(len1, len2);
		}
		
		p = l1;
		for(int i = 0; i < len1 - len2; i++) p = p->next;
		
		ListNode *q = l2;
		while(p) {
			p->val += q->val;
			p = p->next;
			q = q->next;
		}
		
		for(int i = 1; i < len1; i++) {
			p = l1;
			for(int j = 0; j < len1 - i; j++) {
				if(p->next->val >= 10) {
					p->val += p->next->val / 10;
					p->next->val %= 10;
				}
				p = p->next;
			}
		}
		
		if(l1->val >= 10) {
			ListNode *t = new ListNode(l1->val / 10);
			l1->val %= 10;
			t->next = l1;
			l1 = t;
		}
		
		return l1;
		
    }
};

int main() {
	
	int n;
	cin>>n;
	
	ListNode *head1 = new ListNode(0);
	ListNode *p = head1;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		p->next = new ListNode(num);
		p = p->next;
	}
	
	head1 = head1->next;
	
	cin>>n;
	ListNode *head2 = new ListNode(0);
	p = head2;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		p->next = new ListNode(num);
		p = p->next;
	}
	
	head2 = head2->next;
	
	Solution *solution = new Solution();
	ListNode *head = solution->addTwoNumbers(head1, head2);
	while(head) {
		cout<<head->val<<" ";
		head = head->next;
	}
	
	return 0;
}
