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
        ListNode *result = len1 >= len2 ? addTwoNumbers(l1, l2, len1 - len2) : addTwoNumbers(l2, l1, len2 - len1);
        if(result->val >= 10) {
        	ListNode *head = new ListNode(result->val / 10);
        	result->val %= 10;
        	head->next = result;
        	result = head;
		}
		return result;
		
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int diff) {
    	if(l1 == NULL || l2 == NULL) return NULL;
    	ListNode *result = new ListNode(0);
    	if(diff > 0) {
    		result->val = l1->val;
    		result->next = addTwoNumbers(l1->next, l2, diff - 1);
		}else {
			result->val = l1->val + l2->val;
			result->next = addTwoNumbers(l1->next, l2->next, 0);
		}
		
		if(result->next) {
			result->val += result->next->val / 10;
			result->next->val %= 10;
		}
		
		return result;
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
