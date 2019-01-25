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
        ListNode *cur1 = l1, *cur2 = l2, *result = NULL;
        while(len1 > 0 && len2 > 0) {
        	int sum = 0;
        	if(len1 >= len2) {
        		sum += cur1->val;
        		cur1 = cur1->next;
        		len1--;
			}
			if(len1 < len2) {
				sum += cur2->val;
				cur2 = cur2->next;
				len2--;
			}
			result = addToFront(sum, result);
		}
		
		cur1 = result;
		result = NULL;
		int carry = 0;
		while(cur1) {
			carry += cur1->val;
			result = addToFront(carry % 10, result);
			carry /= 10;
			cur1 = cur1->next;
		}
		
		if(carry) result = addToFront(carry, result);
		return result;
    }
    
    ListNode* addToFront(int val, ListNode* head) {
    	ListNode *t = new ListNode(val);
    	t->next = head;
    	return t;
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
