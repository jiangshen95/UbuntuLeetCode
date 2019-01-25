#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> s1, s2;
        ListNode *p = l1;
        while(p) {
        	s1.push(p->val);
        	p = p->next;
		}
		
		p = l2;
		while(p) {
			s2.push(p->val);
			p = p->next;
		}
		
		ListNode *result = new ListNode(0);
		int carry = 0;
		while(!s1.empty() || !s2.empty()) {
			int num1 = 0, num2 = 0;
			if(!s1.empty()) {
				num1 = s1.top();
				s1.pop();
			}
			if(!s2.empty()) {
				num2 = s2.top();
				s2.pop();
			}
			
			carry += num1 + num2;
			result->val = carry % 10;
			ListNode* q = new ListNode(carry / 10);
			q->next = result;
			result = q;
			carry /= 10;
		}
		
		return result->val == 0 ? result->next : result;
		
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
