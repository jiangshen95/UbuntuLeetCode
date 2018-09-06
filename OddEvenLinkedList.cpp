#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *even = head->next;
        ListNode *p, *q;
        
        p = head;
        q = head->next;
        
        while(p->next && q->next) {
        	p->next = p->next->next;
        	q->next = q->next->next;
        	p = p->next;
        	q = q->next;
		}
        
        p->next = even;
        
        return head;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		p->next = new ListNode(num);
		p = p->next;
	} 
	
	head = head->next;
	
	Solution *solution = new Solution();
	head = solution->oddEvenList(head);
	
	while(head) {
		cout<<head->val<<"  ";
		head = head->next;
	}
	
	return 0;
	
}
