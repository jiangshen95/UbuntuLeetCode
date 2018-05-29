#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        *node = *next;
        free(next);
    }
};

int main(){
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	
	a->next = b;
	b->next = c;
	c->next = d;
	
	Solution *solution = new Solution();
	solution->deleteNode(c);
	
	ListNode *p = a;
	while(p){
		cout<<p->val<<" ";
		p = p->next; 
	}
	
	return 0;
}
