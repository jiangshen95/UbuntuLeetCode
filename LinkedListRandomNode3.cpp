#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *c = head;
        int r = c->val;
        for(int i = 1; c != NULL; i++, c = c->next) {
        	if(rand() % i == i - 1) r = c->val;
		}
		return r;
    }
};

int main() {
	
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	
	a->next = b;
	b->next = c;
	
	Solution *solution = new Solution(a);
	cout<<solution->getRandom()<<endl;
	cout<<solution->getRandom()<<endl;
	cout<<solution->getRandom()<<endl;
	
	return 0;
	
}
