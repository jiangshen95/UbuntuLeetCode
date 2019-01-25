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
        
        int len1 = getLength(l1), len2 = getLength(l2);
        int diff = abs(len1 - len2);
        if(len1 < len2) swap(l1, l2);
        
        ListNode* dummy = new ListNode(0);
        ListNode *cur = dummy, *right = cur;
        
        while(diff > 0) {
        	cur->next = new ListNode(l1->val);
        	if(l1->val != 9) right = cur->next;
        	l1 = l1->next;
        	cur = cur->next;
        	diff--;
		}
        
        while(l1) {
        	int val = l1->val + l2->val;
        	if(val > 9) {
        		val %= 10;
        		right->val++;
        		while(right->next) {
        			right->next->val = 0;
        			right = right->next;
				}
				right = cur;
			}
			
			cur->next = new ListNode(val);
			if(val != 9) right = cur->next;
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		
		return dummy->val > 0 ? dummy : dummy->next;
    }
    
    int getLength(ListNode *p) {
    	int len = 0;
    	while(p) {
    		len++;
    		p = p->next;
		}
		return len;
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
